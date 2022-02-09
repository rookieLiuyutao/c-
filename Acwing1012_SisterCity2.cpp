//
// Created by 95853 on 2021/7/16.
//
#include "bits/stdc++.h"
using namespace std;
#define r first
#define l second
const int N = 5010;
int n,dp[N];
pair<int,int >c[N];
int main(){
    cin>>n;
    for(int i = 0; i <n; i++) {
      cin>>c[i].r >>c[i].l;

    }
    int res  =0;
    for(int i = 0; i <n; i++) {
      dp[i] = 1;
      for(int j = 0; j <i; j++) {

          if (c[i].l >c[j].l)dp[i] = max(dp[i],dp[j]+1);
      }
      res = max(res,dp[i]);
    }
    cout<<res<<endl;
}
