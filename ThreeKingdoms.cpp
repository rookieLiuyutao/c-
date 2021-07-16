//
// Created by 95853 on 2021/7/7.
//
#include <bits/stdc++.h>
using std::string;
using std::cin;
using std::cout;
int n, pass;
char card[2020]; // 游戏中的牌堆
int card_top = 1; // 牌用到哪里了
bool over; // 游戏是否结束
bool like[100]; // 主猪眼里的类反猪集合和类反猪数量
int nxt[100]; // 每只猪的下一只猪
struct Node {
    char who, pai[2020]; //身份与手牌
    int cnt; // 牌的数量
    int xie; // 猪的血量
    bool ak; // 是否有连弩
    bool able; // 目前还是否能够出杀
    bool jump; // 目前是否已经跳身份了
} pig[20];
void Get_card(int cur) {
    pig[cur].pai[++pig[cur].cnt] = card[card_top];

    if (card_top < pass)
        card_top ++; // 若牌堆里只剩一张牌了就不必弹出
}
void Insert(int cur) {
    like[cur] = true; // 插入集合
}
void jie_suan(int cur, int to) { // cur干掉了第i只猪
    if (pig[to].who == 'F') {
        bool flag = true;

        for (int i = 1; i <= n; i++) {
            if (pig[i].who == 'F' && pig[i].xie > 0) { // 若有一个反猪还活着
                flag = false; // 说明游戏未结束
                break;
            }
        }

        if (flag)
            over = true; // 无反猪了，游戏结束

        if (over)
            return; // 游戏结束了，不用摸牌了

        Get_card(cur);
        Get_card(cur);
        Get_card(cur); // 立即摸三张牌
    } else if (pig[to].who == 'Z') {
        if (pig[cur].who == 'M') { // 主猪把忠猪干掉了
            for (int i = 1; i <= pig[cur].cnt; i++)
                pig[cur].pai[i] = 'T'; // 清空手牌

            pig[cur].ak = false; // 扔掉装备
        }
    }

    if (to == 1)
        over =  true; // 若主猪被干掉了，游戏直接结束
    else {
        bool flag = true;

        for (int i = 1; i <= n; i++) {
            if (pig[i].who == 'F' && pig[i].xie > 0) { // 若有一个反猪还活着
                flag = false; // 说明游戏未结束
                break;
            }
        }

        if (flag)
            over = true; // 无反猪了，游戏结束
    }
}
char another(char c) {
    if (c == 'Z' || c == 'M')
        return 'F';
    else
        return 'Z';
}
bool same(char A, char B) { // 判断两只猪势力是否相同
    if (A == 'F' && B == 'F')
        return true;

    if (A == 'Z' && B == 'Z')
        return true;

    if (A == 'Z' && B == 'M')
        return true;

    if (A == 'M' && B == 'Z')
        return true;

    if (A == 'M' && B == 'M')
        return true;

    return false;
}
bool ask_wu_xie(int start, char now) {
    int i = start;

    while (1) { // 不停的循环询问无懈
        if (pig[i].xie == 0) { // 猪挂了不用管他
            i = i % n + 1;

            if (i == start)
                return false;

            continue;
        }

        int t = -1; // 存储无懈的位置

        for (int j = 1; j <= pig[i].cnt; j++) {
            if (pig[i].pai[j] == 'J') {
                t = j;
                break;
            }
        }

        if (t == -1) { // 说明这只猪没有无懈，不用管它了
            i = i % n + 1;

            if (i == start)
                return false;

            continue;
        }

        if (same(pig[i].who, now)) { // 若此时势力相同
            pig[i].pai[t] = 'T'; // 打出无懈
            pig[i].jump = true; // 打出无懈肯定跳了身份
            like[i] = false; // 若其是忠猪，则从类反猪名单上划掉
            now = another(now); // 仔细想想

            if (!ask_wu_xie(i, now))
                return true;
            else
                return false;
        }

        i = i % n + 1; // 继续逆时针转

        if (i == start)
            return false;
    }
}
void bin_si(int from, int to) {
    pig[to].xie --;

    if (pig[to].xie == 0) { // 若此时这只猪处于濒死状态
        bool alive = false;

        for (int j = 1; j <= pig[to].cnt; j++) {
            if (pig[to].pai[j] == 'P') { // 如果有桃赶紧吃掉（不然就挂掉了）
                pig[to].xie ++; // 回一滴血
                pig[to].pai[j] = 'T'; // 用过这张牌了
                alive = true;
                break;
            }
        }

        if (!alive) { // 说明这只猪挂掉了
            jie_suan(from, to); // 结算结果（摸三张牌、弃牌、游戏结束之类的）
        }
    }
}
bool Kill(int cur, int i) {
    if (!pig[cur].able)
        return false; // 若此时都不能出杀了肯定false

    int tt = -1;

    for (int j = cur % n + 1; j != cur; j = j % n + 1) {
        if (pig[j].xie) { // 找到第一只活着的猪
            tt = j;
            break;
        }
    }

    if ((cur == 1 && like[tt]) || (pig[tt].jump &&
                                   !same(pig[cur].who, pig[tt].who))) { // 如果2号位是类反猪或已跳反
        if (!pig[cur].ak)
            pig[cur].able = false;

        pig[cur].pai[i] = 'T'; // 用掉这张杀
        pig[cur].jump = true; // 跳身份了
        like[cur] = false;
        int t = -1;

        for (int j = 1; j <= pig[tt].cnt; j++) {
            if (pig[tt].pai[j] == 'D') {
                t = j;
                break;
            }
        }

        if (t != -1) { // 说明有闪
            pig[tt].pai[t] = 'T'; // 出闪
        } else { // 否则要掉血
            bin_si(cur, tt);
        }

        return true;
    }

    return false;
}
void action(int from, int to) {
    if (pig[to].jump)
        if (ask_wu_xie(from, pig[to].who))
            return; // 若询问无懈成功，直接return

    if (from == 1 && pig[to].who == 'Z') { // 若发起决斗者是主猪，且被决斗者是忠猪
        bin_si(1, to); // 忠猪直接掉血
    } else {
        int tmp1 = 0, tmp2 = 0;

        for (int i = 1; i <= pig[from].cnt; i++)
            if (pig[from].pai[i] == 'K')
                tmp1 ++;

        for (int i = 1; i <= pig[to].cnt; i++)
            if (pig[to].pai[i] == 'K')
                tmp2 ++;

        if (tmp2 > tmp1) {
            for (int i = 1; i <= pig[from].cnt; i++)
                if (pig[from].pai[i] == 'K')
                    pig[from].pai[i] = 'T';

            int now = 0;

            for (int i = 1; i <= pig[to].cnt; i++) {
                if (pig[to].pai[i] == 'K') {
                    now ++;
                    pig[to].pai[i] = 'T';

                    if (now == tmp1 + 1)
                        break;
                }
            }

            bin_si(to, from);
        } else {
            for (int i = 1; i <= pig[to].cnt; i++)
                if (pig[to].pai[i] == 'K')
                    pig[to].pai[i] = 'T';

            int now = 0;

            for (int i = 1; i <= pig[from].cnt; i++) {
                if (now == tmp2)
                    break;

                if (pig[from].pai[i] == 'K') {
                    now ++;
                    pig[from].pai[i] = 'T';
                }
            }

            bin_si(from, to);
        }
    }
}
bool jue_dou(int cur, int i) {
    int t = -1;

    if (pig[cur].who == 'Z' || pig[cur].who == 'M') {
        for (int j = cur % n + 1; j != cur; j = j % n + 1) {
            if (pig[j].xie == 0)
                continue;

            if ((cur == 1 && like[j]) || (pig[j].jump &&
                                          !same(pig[cur].who, pig[j].who))) { // 找到第一只能决斗的目标
                t = j;
                break;
            }
        }
    } else if (pig[cur].who == 'F') {
        t = 1;
    }

    if (t == -1)
        return false; // 没有找到目标
    else {
        pig[cur].jump = true; // 既然决斗了肯定跳了身份
        like[cur] = false;
        pig[cur].pai[i] = 'T';
        action(cur, t); // 开始决斗
        return true;
    }
}
void AOE(int cur, bool which) { // 第cur只猪使用了南蛮入侵 / 万箭齐发
    for (int i = cur % n + 1; i != cur; i = i % n + 1) { // 开始逆时针结算
        if (pig[i].xie == 0)
            continue; // 若这只猪已经挂了直接continue

        bool flag = false;

        if (pig[i].jump) { // 如果跳身份了别人才肯给他出无懈
            if (ask_wu_xie(cur, pig[i].who))
                continue; // 若询问无懈成功直接continue
        }

        for (int j = 1; j <= pig[i].cnt; j++) { // 枚举这只猪的牌
            if (which == 0) { // 说明是南蛮入侵
                if (pig[i].pai[j] == 'K') { // 若这张牌是杀
                    pig[i].pai[j] = 'T';
                    flag = true;
                    break;
                }
            } else { // 说明是万箭齐发
                if (pig[i].pai[j] == 'D') { // 若这张牌是闪
                    pig[i].pai[j] = 'T';
                    flag = true;
                    break;
                }
            }
        }

        if (!flag) { // 若这只猪没有杀，说明要掉血
            bin_si(cur, i);

            if (over)
                return; // 游戏结束就不必再往下

            // 运行到此说明没挂或者用桃子救过来了
            if (i == 1 && !pig[cur].jump) // 若这只猪是主猪且造成伤害的猪还未跳身份
                Insert(cur); // 将第cur只猪插入到类反猪集合中
        }
    }
}
bool can_use(int cur, char tmp, int i) { // 表示第cur只猪，用了tmp这种牌
    if (tmp == 'T')
        return false; // 若这张牌是空的直接false

    if (tmp == 'D')
        return false; // 若这张牌是闪，也不可能在出牌阶段出

    if (tmp == 'J')
        return false; // 若这张牌是无懈，也不可能在这时候出

    if (tmp == 'Z') {
        pig[cur].ak = true; // 有连弩了
        pig[cur].able = true;
        pig[cur].pai[i] = 'T'; // 这张牌用了
        return true;
    }

    if (tmp == 'P') { // 若这张牌是桃子
        if (pig[cur].xie < 4) { //不满血
            pig[cur].xie ++; // 加血
            pig[cur].pai[i] = 'T'; // 用了这张牌
            return true;
        } else
            return false;
    }

    if (tmp == 'N') { // 如果这张牌是南蛮入侵
        AOE(cur, 0); // 使用南蛮入侵
        pig[cur].pai[i] = 'T'; // 用了这张牌
        return true;
    }

    if (tmp == 'W') { // 如果这张牌是万箭齐发
        AOE(cur, 1); // 使用万箭齐发
        pig[cur].pai[i] = 'T'; // 用了这张牌
        return true;
    }

    if (tmp == 'K') {
        if (Kill(cur, i)) { // 若可以杀
            return true;
        } else
            return false;
    }

    if (tmp == 'F') {
        if (jue_dou(cur, i)) { // 若可以决斗
            return true;
        } else
            return false;
    }

    return false;
}
void Use_card(int cur) {
    while (1) {
        if (pig[cur].xie == 0)
            break;

        bool fail = false;

        for (int i = 1; i <= pig[cur].cnt; i++) {
            if (can_use(cur, pig[cur].pai[i], i)) {
                if (over)
                    return;

                fail = true;
                break; // 若找到一张能出的牌，就出然后break
            }
        }

        if (!fail)
            break; // 没有一张能出的break就OK了
    }
}
int main() {
    scanf("%d%d", &n, &pass); // 猪的数量和初始时牌堆中牌的数量
    char str[20];
    pig[1].jump = true; // 主猪的身份是明的

    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        pig[i].who = str[0]; // 身份：M、Z，F

        for (int j = 1; j <= 2005; j++)
            pig[i].pai[j] = 'T'; //T就是已经用过的牌，这里初始化

        for (int j = 1; j <= 4; j++) {
            scanf("%s", str);
            pig[i].pai[j] = str[0];
        }

        pig[i].cnt = 4;
        pig[i].xie = 4;
        pig[i].ak = false;

        if (i != 1)
            pig[i].jump = false;
    }

    for (int i = 1; i <= pass; i++) {
        scanf("%s", str);
        card[i] = str[0];
    }

    for (int i = 1;; i = i % n + 1) { // 逆时针轮流出牌
        if (over)
            break;

        if (pig[i].xie == 0)
            continue; // 如果挂了直接跳过

        pig[i].able = true; // 目前可以使用杀
        Get_card(i);
        Get_card(i); //从牌堆里摸两张牌
        Use_card(i);
    }

    if (pig[1].xie == 0) {
        puts("FP");
    } else
        puts("MP");

    for (int i = 1; i <= n; i++) {
        if (pig[i].xie == 0) {
            puts("DEAD");
            continue;
        }

        for (int j = 1; j <= pig[i].cnt; j++) {
            if (pig[i].pai[j] != 'T')
                cout << pig[i].pai[j] << " ";
        }

        puts("");
    }

    return 0;
}
