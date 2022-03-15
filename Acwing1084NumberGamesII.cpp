//
// Created by 刘宇韬 on 2022/3/15.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 35;
int dp[N][N] ,s[N],cnt;
int mod;
int dfs(int u,int sum,int limit){
  if (!u) return sum %mod==0;
  if (!limit&&dp[u][sum]!=-1) return dp[u][sum];
  int res = 0;
  int up = limit? s[u]:9;
  for(int i = 0; i <=up; i++) {
    res+=dfs(u-1, sum +i,limit&&i ==up );
  }
  return limit?res:dp[u][sum];
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
  int l,r;
  while (cin>>l>>r>>mod){
    cout<<work(r)-work(l-1)<<endl;
  }
}    