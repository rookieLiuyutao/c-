//
// Created by 刘宇韬 on 2022/3/5.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 405,INF = 0x3f3f3f3f;
int dp[N][N],f[N][N];
int a[N],s[N];
int n;
int main(){
  cin>>n;
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
    a[i+n] = a[i];
  }
  for(int i = 1; i <2*n; i++) {
    s[i] = s[i-1]+a[i];
  }
  memset(dp,0x3f,sizeof dp);
  memset(f,-0x3f,sizeof f);
  for(int len = 1; len <=n; len++) {
    for(int l = 1; l+len-1 <=n<<1; l++) {
      int r = l+len-1;
      if (len ==1) {
        dp[l][r] = 0;
        f[l][r] = 0;
      } else{
        for(int k = l; k <r; k++) {
          dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]+s[r]-s[l-1]);
          f[l][r] = max(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
        }
      }
    }
  }
  int minv = INF,maxv = -INF;
  for(int i = 1; i <=n; i++) {
    maxv = max(f[i][i+n-1],maxv);
    minv = min(minv,dp[i][i+n-1]);
  }
  cout<<minv<<endl;
  cout<<maxv<<endl;
}