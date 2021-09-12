/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1301
 */

#include "iostream"
#include "cstring"
#include "algorithm"

using namespace std;
const int N = 100010;
int n, dp[N], a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int first;
        cin>>first;
        dp[1] = first;
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            dp[i] = max(dp[i - 1], dp[i - 2] + x);
        }
        cout << dp[n] << endl;
    }

}
