//
// Created by 95853 on 2021/7/20.
//
/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1295
 */
#include "bits/stdc++.h"
using namespace std;
const int N = 20010;
int n,v,dp[N];
int main(){
    cin >> v >> n;
    for(int i = 1; i <=n; i++) {
      int v;
      cin>>v;
      for(int j = v; j >= v; j--) {
        dp[j] = max(dp[j],dp[j-v]+v);
      }
    }
    cout << v - dp[v] << endl;
}