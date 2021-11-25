//
// Created by 95853 on 2021/11/25.
//
#include "bits/stdc++.h"

using namespace std;
const int N = 100010;
struct IP {
    //其中地址的状态有未分配、待分配、占用、过期四种。
    //0：未分配；1：待分配；2：占用；3：过期
    int state;
    int t;
    string owner;
} ips[N];


int n, m, t_def, t_max, t_min;
string h;


void update_ips_state(int tc) {
    for (int i = 1; i <= n; i++) {
        //处于未分配状态的 IP 地址没有占用者，而其余三种状态的 IP 地址均有一名占用者。
        if (ips[i].t && ips[i].t <= tc) {
            //若该地址的状态是待分配，则该地址的状态会自动变为未分配，且占用者清空，过期时刻清零
            if (ips[i].state == 1) {
                ips[i].state = 0;
                ips[i].owner = "";
                ips[i].t = 0;
            } else {
                //否则该地址的状态会由占用自动变为过期，且过期时刻清零

                ips[i].state = 3;
                ips[i].t = 0;
            }
        }
    }
}

int get_ip_by_owner(string client) {
    for (int i = 1; i <= n; i++)
        if (ips[i].owner == client)
            return i;
    return 0;
}

int get_id_by_state(int state) {
    for (int i = 1; i <= n; i++) {
        if (ips[i].state == state)return i;
    }
    return 0;
}


int main() {
    cin >> n >> t_def >> t_max >> t_min >> h;
    cin >> m;
    while (m--) {
        int tc;
        string client, server, type;
        int id, te;
        cin >> tc >> client >> server >> type >> id >> te;
        //不处理的情况
        if (server != h && server != "*" ) {
            if (type!="REQ")continue;
        }
        if (type != "REQ" && type != "DIS")continue;
        if ((server == "*" && type != "DIS" )|| (server == h && type == "DIS"))continue;
        //每处理一条报文，都要更新一次ip池
        update_ips_state(tc);
        //对于 Discover 报文，按照下述方法处理：
        if (type == "DIS") {
            int chose_id = get_ip_by_owner(client);
            //若没有，则选取最小的状态为未分配的 IP 地址；
            if (!chose_id)chose_id = get_id_by_state(0);
            //若没有，则选取最小的状态为过期的 IP 地址；
            if (!chose_id)chose_id = get_id_by_state(3);
            //若没有，则不处理该报文，处理结束；
            if (!chose_id)continue;

            //将该 IP 地址状态设置为待分配，占用者设置为发送主机；
            ips[chose_id].state = 1;
            ips[chose_id].owner = client;
            //若报文中过期时刻为 0 ，则设置过期时刻为 t+Tdef
            if (te == 0) {
                ips[chose_id].t = tc + t_def;
            } else {
                //否则根据报文中的过期时刻和收到报文的时刻计算过期时间，
                int spend = te - tc;
                //判断是否超过上下限：若没有超过，则设置过期时刻为报文中的过期时刻；
                //否则则根据超限情况设置为允许的最早或最晚的过期时刻；
                spend = max(spend, t_min);
                spend = min(spend, t_max);
                ips[chose_id].t = spend + tc;
            }
            //向发送主机发送 Offer 报文，其中，IP 地址为选定的 IP 地址，过期时刻为所设定的过期时刻
            cout << h << ' ' << client << ' ' << "OFR" << ' ' << chose_id << ' ' << ips[chose_id].t << endl;
        } else {
            //对于 Request 报文，按照下述方法处理：
            //检查接收主机是否为本机：
            if (server != h) {
                //若不是，则找到占用者为发送主机的所有 IP 地址，
                for (int i = 1; i <= n; i++) {
                    if (ips[i].owner == client) {
                        //对于其中状态为待分配的，将其状态设置为未分配，并清空其占用者，清零其过期时刻，处理结束；
                        if (ips[i].state == 1) {
                            ips[i].state = 0;
                            ips[i].owner = "";
                            ips[i].t = 0;
                        }
                    }
                }
                continue;
            }
            //检查报文中的 IP 地址是否在地址池内，且其占用者为发送主机，
            if (!(id <= n && id >= 1 && ips[id].owner == client)) {
                //若不是，则向发送主机发送 Nak 报文，处理结束；
                cout << h << ' ' << client << ' ' << "NAK" << ' ' << id << ' ' << 0 << endl;
            } else {
                //无论该 IP 地址的状态为何，将该 IP 地址的状态设置为占用；
                ips[id].state = 2;
                //与 Discover 报文相同的方法，设置 IP 地址的过期时刻；
                //否则根据报文中的过期时刻和收到报文的时刻计算过期时间，
                if (te == 0) {
                    ips[id].t = tc + t_def;
                } else {
                    int spend = te - tc;
                    //判断是否超过上下限：若没有超过，则设置过期时刻为报文中的过期时刻；
                    //否则则根据超限情况设置为允许的最早或最晚的过期时刻；
                    spend = max(spend, t_min);
                    spend = min(spend, t_max);
                    ips[id].t = spend + tc;
                }

                //向发送主机发送 Ack 报文。
                cout << h << ' ' << client << ' ' << "ACK" << ' ' << id << ' ' << ips[id].t << endl;
            }
        }


    }
}





