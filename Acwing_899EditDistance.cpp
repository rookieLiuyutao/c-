//
// Created by 95853 on 2021/7/18.
//
/**
 * https://www.acwing.com/problem/content/description/901/
 */
#include "bits/stdc++.h"
using namespace std;
int n, m;
const int N = 1010;
int dp[N][N];

int dis(string a, string b) {
    int la = a.size();
    int lb = b.size();
    for (int i = 1; i <= la; i++)dp[i][0] = i;
    for (int i = 1; i <= lb; i++)dp[0][i] = i;

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            dp[i][j] = min(dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]), min(dp[i - 1][j], dp[i][j - 1]) + 1);
        }
    }
    return dp[la][lb];


}

int main() {
    cin >> n >> m;
    vector<string> st(n);
    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }
    while (m--) {
        int res = 0;
        string x;
        int q;
        cin >> x >> q;
        for (string p:st) {
            if (dis(p, x) <= q) {
                res++;
            }
        }
        cout << res << endl;
    }

}
