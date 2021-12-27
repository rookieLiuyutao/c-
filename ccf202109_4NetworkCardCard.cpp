
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 16, M = 1 << N;
double dp[M][N * 5], a[N];
int n, k;

/**
 *
 * @param card 还剩下多少张牌没有集齐
 * @param coin 手里的硬币数量
 * @param state 牌的状态
 * @param cnt 抽了多少次卡
 * @return
 */
double dfs(int card, int coin, int state, int cnt) {
    if (dp[state][coin])return dp[state][coin];
    //如果手里的硬币数能把剩下的卡牌都换到，就返回
    if (coin >= card * k) {
        return cnt;
    }
    for (int i = 0; i < n; i++) {
        if ((state >> i) & 1) {
            dp[state][coin] += a[i] * dfs(card, coin + 1, state, cnt + 1);
        } else {
            dp[state][coin] += a[i] * dfs(card - 1, coin, state | (1 << i), cnt + 1);
        }
    }

    return dp[state][coin];
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> a[i];

    printf("%.10lf", dfs(n, 0, 0, 0));
}