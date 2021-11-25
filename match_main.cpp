// 这个自动生成的框架文件演示了如何构建服务器。
// 你应该把它复制到另一个文件名以避免覆盖它。

#include "match_server/Match.h"
#include "save_client/Save.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/ThreadFactory.h>
#include <thrift/TToString.h>
#include <iostream>
#include <mutex>  //锁的头文件
#include <thread>  //线程的头文件
#include <condition_variable>  //条件变量的头文件
#include <queue>
#include <vector>
#include <unistd.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::match_service;
using namespace ::save_service;
using namespace std;

struct Task {
    User user;
    string type;
};

struct MessageQueue {
    //队列是互斥的，同时只能有一个线程访问队列
    queue<Task> q;
    mutex m;
    condition_variable cv;
} message_queue;

class Poll {
public:
    void add(User user) {
        users.push_back(user);
        wt.push_back(0);
    }

    void remove(User user) {
        for (uint32_t i = 0; i < users.size(); i++) {
            if (users[i].id == user.id) {
                users.erase(users.begin() + i);
                break;
            }
        }
    }

    bool check_match(uint32_t i, uint32_t j) {
        auto a = users[i], b = users[j];

        int dt = abs(a.score - b.score);
        int a_max_dif = wt[i] * 50;
        int b_max_dif = wt[j] * 50;

        return dt <= a_max_dif && dt <= b_max_dif;
    }

    void match() {
        for (uint32_t i = 0; i < wt.size(); i++)
            wt[i]++;   // 等待秒数 + 1
//            sort(users.begin(), users.end(), [&](User &a, User b) {
//                return a.score < b.score;
//            });
        while (users.size() > 1) {
            bool flag = true;
            for (uint32_t i = 0; i < users.size(); i++) {
                for (uint32_t j = i + 1; j < users.size(); j++) {
                    if (check_match(i, j)) {
                        auto a = users[i], b = users[j];
                        users.erase(users.begin() + j);
                        users.erase(users.begin() + i);
                        wt.erase(wt.begin() + j);
                        wt.erase(wt.begin() + i);
                        save_result(a.id, b.id);
                        flag = false;
                        break;
                    }
                }

                if (!flag) break;
            }

            if (flag) break;
        }
    }


    void save_result(int a, int b) {
        printf(" %d 和 %d 匹配成功\n", a, b);

        std::shared_ptr<TTransport> socket(new TSocket("123.57.47.211", 9090));
        std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
        SaveClient client(protocol);

        try {
            transport->open();
            //----------在此之间实现自己的业务------------
            //第二个参数是myserver密码的MD5值的前8位
            client.save_data("acs_1642", "6a46581f", a, b);

            //-----------------------------------------
            transport->close();
        } catch (TException &tx) {
            cout << "ERROR: " << tx.what() << endl;
        }

    }

private:
    vector<User> users;
    vector<int> wt;
} pool;


class MatchHandler : virtual public MatchIf {
public:
    MatchHandler() {
        // 在这里初始化
    }

    int32_t add_user(const User &user, const std::string &info) {
        // 在这里实现接口
        printf("add_user\n");


        unique_lock<mutex> lock1(message_queue.m);//加锁
        message_queue.q.push({user, "add"});
        //当有操作时，应该唤醒线程
        message_queue.cv.notify_all();


        return 0;
    }

    int32_t remove_user(const User &user, const std::string &info) {
        // 在这里实现接口
        printf("remove_user\n");


        unique_lock<mutex> lock1(message_queue.m);//加锁,在队列为空的时候，不能拿到锁
        message_queue.q.push({user, "remove"});
        //当有操作时，应该唤醒线程
        message_queue.cv.notify_all();

        return 0;
    }

};

class MatchCloneFactory : virtual public MatchIfFactory {
public:
    ~MatchCloneFactory() override = default;

    MatchIf *getHandler(const ::apache::thrift::TConnectionInfo &connInfo) override {
        std::shared_ptr<TSocket> sock = std::dynamic_pointer_cast<TSocket>(connInfo.transport);
//        cout << "Incoming connection\n";
//        cout << "\tSocketInfo: "  << sock->getSocketInfo() << "\n";
//        cout << "\tPeerHost: "    << sock->getPeerHost() << "\n";
//        cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
//        cout << "\tPeerPort: "    << sock->getPeerPort() << "\n";
        return new MatchHandler;
    }

    void releaseHandler(MatchIf *handler) override {
        delete handler;
    }
};

//线程操作的函数
void consume_task() {
    while (true) {
        unique_lock<mutex> lock1(message_queue.m);//加锁
        if (message_queue.q.empty()) {
            //因为队列初始一定是空的，如果直接continue，会死循环。因此在初始时，应在有add操作后，才应该执行这里
            //continue
//            message_queue.cv.wait(lock1);
            lock1.unlock();
            pool.match();
            sleep(1);
            //当队列为空时。当前线程放弃持有锁，由其他线程持有锁，在进行匹配。这个过程1s后，再进行后面的判断
        } else {
            auto task = message_queue.q.front();
            message_queue.q.pop();
            //因为只有队列是互斥的，为了保证程序的快速运行，操作完队列就应该释放锁
            lock1.unlock();
            //具体任务
            if (task.type == "add") {
                pool.add(task.user);
//                printf("执行了1次add");
            } else if (task.type == "remove") {
                pool.remove(task.user);
            }
//            pool.match();

        }
    }
}

int main(int argc, char **argv) {
    TThreadedServer server(
            std::make_shared<MatchProcessorFactory>(std::make_shared<MatchCloneFactory>()),
            std::make_shared<TServerSocket>(9090), //port
            std::make_shared<TBufferedTransportFactory>(),
            std::make_shared<TBinaryProtocolFactory>()
    );
    printf("Match server start\n");

    thread matching_thread(consume_task);


    server.serve();
    return 0;
}
