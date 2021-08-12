//
// Created by 95853 on 2021/7/24.
//
/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1269
 */
#include "iostream"

using namespace std;
const int N = 6010;
int n, m, dp[N];
int main() {
    cin >> n >> m;
    while (n--) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int i = m; i > 0; i--) {
            for (int j = 0; j <= s && j * v <= i; j++) {
                dp[i] = max(dp[i], dp[i - j * v] + j * w);
            }
        }
    }
    cout << dp[m] << endl;
}
