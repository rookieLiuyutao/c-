//
// Created by 刘宇韬 on 2022/3/15.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 15;
int dp[N][N] ,s[N],cnt;


int dfs(int u,int p,int limit){
  if (!u) return 1;
  if (!limit&&dp[u][p]!=-1) return dp[u][p];
  int res = 0;
  int up = limit? s[u]:9;
  for(int i = 0; i <=up; i++) {
    if (i==4||(p==6&&i==2)) continue;
    res+= dfs(u-1,i,limit&&i==up);
  }
  return limit? res:dp[u][p] = res;
}

int work(int n){
  memset(dp,-1,sizeof dp);
  cnt = 0;
  while (n){
    s[++cnt] = n%10;
    n/=10;
  }
  return dfs(cnt,0,1);
}


int main(){
  int n,m;
  while (cin>>n>>m,n&&m){
    cout<<work(m)- work(n-1)<<endl;
  }
}