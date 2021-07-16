/**
 * 线性dp
 * https://www.luogu.com.cn/problem/P1020
 */
#include "bits/stdc++.h"

using namespace std;
const int N = 100010;
int n, dp[N], g[N], a[N];

int main() {
    while (cin >> a[n])n++;
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        while (k < count && g[k] < a[i]) {
            k++;
        }
        g[k] = a[i];
        if (k >= count)count++;
    }
    cout << res << endl;
    cout << count << endl;
}
