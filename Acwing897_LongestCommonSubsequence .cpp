
#include "bits/stdc++.h"
using namespace std;

const int N = 1010;
char a[N],b[N];
int dp[N][N];
int n,m;
int main(){
    cin>>n>>m>>(a+1)>>(b+1);

    for(int i = 1; i <=n; i++) {
      for(int j = 1; j <=m; j++) {
          if (a[i]==b[j]){
              dp[i][j] =dp[i-1][j-1]+1;
          } else{
              dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
          }

      }
    }
    cout<<dp[n][m]<<endl;

}
