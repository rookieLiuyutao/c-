/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1285
 */
#include "bits/stdc++.h"

using namespace std;
const int N = 1010;

int arr[N], dp[N], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = arr[i];
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
//    for(int i = 1; i <=n; i++) {
//      cout<<dp[i]<<' ';
//    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i]);
    }

    cout <<res << endl;
}
