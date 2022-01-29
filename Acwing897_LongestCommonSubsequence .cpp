
#include "bits/stdc++.h"
using namespace std;

const int N = 1010;
char a[N], range[N];
int dp[N][N];
int n,pass;
int main(){
    cin >> n >> pass >> (a + 1) >> (range + 1);

    for(int i = 1; i <=n; i++) {
      for(int j = 1; j <= pass; j++) {
          if (a[i]== range[j]){
              dp[i][j] =dp[i-1][j-1]+1;
          } else{
              dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
          }

      }
    }
    cout << dp[n][pass] << endl;

}
