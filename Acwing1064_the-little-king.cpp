//
// Created by 95853 on 2021/10/26.
//
#include "bits/stdc++.h"

using namespace std;

const int N = 12, M = 1 << N;
vector<int> range;
vector<int> head[M];
int cnt[M], n, k;
int dp[N][N*N][M];

bool check(int x) {
    for (int i = 0; i < n-1; i++) {
        if ((x >> i & 1) && (x >> (i + 1)) & 1)return false;
    }
    return true;
}

int lower_bit(int x) {
    int res = 0;
    for (int i = 0; i < n; i++) res += x >> i & 1;
    return res;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < 1<<n; i++) {
        if (check(i)) {
          range.push_back(i);
            cnt[i] = lower_bit(i);
        }
    }

    for (int i = 0; i < range.size(); i++) {
        for (int j = i; j < range.size(); j++) {
            if ((range[i] & range[j]) == 0 && check(range[i] | range[j])) {
                head[range[i]].push_back(range[j]);
                if (i != j) {
                    head[range[j]].push_back(range[i]);
                }
            }
        }
    }

    dp[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= k; j++) {
            for (auto &p: range) {
                for (auto &q:head[p]) {
                    if (j - cnt[p] >= 0) {
                        dp[i][j][p] += dp[i - 1][j - cnt[p]][q];
                    }
                }
            }
        }
    }
    cout << dp[n + 1][k][0];
}
