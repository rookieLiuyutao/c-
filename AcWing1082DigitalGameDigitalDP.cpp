//
// Created by 刘宇韬 on 2022/3/14.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 35;
int n;
// f[i, j]表示一共有i位，且最高位填j的数的个数

int dp[N][N];
int s[N],cnt;

int dfs(int u,int st,int op){
  if (u==0) return 1;
  if (!op&&dp[u][st]!=-1) return dp[u][st];
  int res = 0;
  int last = op?s[u]:9;
  for(int i = st; i <=last; i++) {
    res+= dfs(u-1,i,op&&i == s[u]);
  }
  return op?res:dp[u][st] = res;
}

int work(int n){
  memset(dp,-1,sizeof dp);
  cnt = 0;
  while (n) {
    s[++cnt] = n%10;
    n/=10;
  }
  return dfs(cnt,0,1);

}

int main(){

  int n,m;
  while (cin>>n>>m){
    cout<<work(m)- work(n-1)<<endl;
  }
}
