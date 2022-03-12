//
// Created by 刘宇韬 on 2022/3/5.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 205;
int n;
int s[N],a[N],w[N];
int dp[N][N];
int main(){
  cin>>n;
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
    a[n+i] = a[i];
  }

  for(int len = 2; len <=n+1; len++) {
    for(int l = 1; l+len-1 <=n<<1; l++) {
      int r = l+len-1;
      if (len==2)dp[l][r] = 0;
      else{
        for(int k = l+1; k <r; k++) {
          dp[l][r] = max(dp[l][r],dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
        }
      }
    }
  }
  int res = 0;
  for(int i = 1; i <=n; i++) {
    res = max(res,dp[i][i+n]);
  }
  cout<<res;

}