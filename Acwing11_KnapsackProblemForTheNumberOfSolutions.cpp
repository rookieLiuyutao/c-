//
// Created by 95853 on 2021/7/19.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1010;
int f[N] , cnt[N];
int mod = 1e9 + 7;
int n , v ;
int main() {
    cin >> n >> v;

    for (int i = 0 ; i <= v ; i ++ ) cnt[i] = 1; // 表示每一个物品初始时都可以被选
    for (int i = 1;  i <= n ; i ++ ) {
        int v , w;
        cin >> v >> w;
        for (int j = v ; j >= v ; j -- ) {
            int value = f[j - v] + w;
            if (value > f[j]) {
                f[j] = value;
                cnt[j] = cnt[j - v];
            }
            else if (value == f[j]) cnt[j] = (cnt[j] + cnt[j - v]) % mod;
        }
    }
    cout << cnt[v];
    for(int i = 0; i <= v; i++) {
      cout<<f[i]<<' ';
    }
    puts("");
    for(int i = 0; i <= v; i++) {
        cout<<cnt[i]<<' ';
    }
    return 0;
}



