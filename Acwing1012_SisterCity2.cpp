//
// Created by 95853 on 2021/7/16.
//
#include "bits/stdc++.h"
using namespace std;
#define x first
#define y second
const int N = 5010;
int n,dp[N];
pair<int,int >c[N];
int main(){
    cin>>n;
    for(int i = 0; i <n; i++) {
      cin>>c[i].x>>c[i].y;

    }
    int res  =0;
    for(int i = 0; i <n; i++) {
      dp[i] = 1;
      for(int j = 0; j <i; j++) {

          if (c[i].y>c[j].y)dp[i] = max(dp[i],dp[j]+1);
      }
      res = max(res,dp[i]);
    }
    cout<<res<<endl;
}
