//
// Created by 95853 on 2021/9/18.
//
#include "bits/stdc++.h"

using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;
int g[N][N];
int n, m;

int main() {
    cin >> n >> m;
    int sum = 0;
    int who = -1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m+1; j++) {
            cin >> g[i][j];
        }
        sum += g[i][0];
    }
    int res = INF;
    for (int i = 1; i < n; i++) {
        int x = 0;
        for (int j = 1; j < m+1; j++) {
            x += g[i][j];
        }
        int t = g[i][0] - x;
        sum -= x;
        if (t < res) {
            res = t;
            who  = i;
        }
    }
    cout<<sum<<' '<<who<<res<<endl;
}
