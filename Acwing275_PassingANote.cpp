//
// Created by 95853 on 2021/7/14.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 52;
int n, pass, w[N][N], dp[N + N][N][N];

int main() {
    cin >> n >> pass;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= pass; j++) {
            cin >> w[i][j];
        }
    }
    for (int k = 2; k <= pass + n; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 > 0 && j1 <= pass && j2 > 0 && j2 <= pass) {
                    int t = w[i1][j1];
                    if (i1 != i2) {
                        t += w[i2][j2];
                    }
                    for (int i = 0; i <= 1; i++) {
                        for (int j = 0; j <= 1; j++) {
                            dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1 - i][i2 - j] + t);
                        }
                    }
                }
            }
        }
    }
    cout << dp[n + pass][n][n] << endl;
}
