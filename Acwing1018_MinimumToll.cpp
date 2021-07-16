/**
* http://ybt.ssoier.cn:8088/problem_show.php?pid=1287
*/

#include "bits/stdc++.h"

using namespace std;
const int N = 102;
int dp[N][N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            int a = dp[i - 1][j], b = dp[i][j - 1];
            if (i == 1)dp[i][j] = b + x;
            else if (j == 1)dp[i][j] = a + x;
            else dp[i][j] = min(a, b) + x;
        }
    }
    cout << dp[n][n] << endl;
}
