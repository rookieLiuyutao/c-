//
// Created by 95853 on 2021/7/20.
//
/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1292
 */
#include "bits/stdc++.h"

using namespace std;
const int N = 1010, M = 505, K = 105;
int n, v, m, dp[N][M];

int main() {
    //v(0<N<1000)，m(0<M<500)，n(0<K<100)，分别代表小智的精灵球数量、皮卡丘初始的体力值、野生小精灵的数量。
    //其中花费为精灵球和比卡丘体力值
    //价值为捕捉到的野生精灵的数量，都为1
    //野生小精灵数量为物品数量
    cin >> v >> m >> n;
    for (int i = 0; i < n; i++) {
        int sv, sm;
        cin >> sv >> sm;
        for (int j = v; j >= sv; j--) {
            for (int k = m-1; k >= sm; k--) {
                dp[j][k] = max(dp[j][k], dp[j - sv][k - sm] + 1);
            }
        }
    }
    cout << dp[v][m-1] << ' ';
    int k = m;
    while (k>0&&dp[v][k-1] == dp[v][m-1])k--;
    cout<<m-k<<endl;
}
