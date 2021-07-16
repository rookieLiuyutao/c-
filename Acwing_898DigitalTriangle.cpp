/**
 * https://www.acwing.com/problem/content/900/
 */
#include "bits/stdc++.h"
using namespace std;
const int N = 510;
int tr[N][N],dp[N][N];
int n;
int main(){
    cin>>n;

    for(int i = 1; i <=n; i++) {
      for(int j = 1; j <=i; j++) {
        cin>>tr[i][j];

      }
    }
    for(int i = 0; i <=n; i++) {
        for(int j = 0; j <=i+1; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    dp[1][1] = tr[1][1];

    for(int i = 2; i <=n; i++) {
      for(int j = 1; j <=i; j++) {
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+tr[i][j];
      }
    }

    int res = INT_MIN;
    for(int i = 1; i <=n; i++) {
      res = max(res,dp[n][i]);
    }

    for(int i = 1; i <=n; i++) {
      for(int j = 1; j <=i; j++) {
        cout<<dp[i][j]<<' ';
      }
        puts("");
    }

    cout<<res<<endl;

}
