/**
 * @see 区间dp https://www.acwing.com/problem/content/284/
 */

#include "iostream"
#include "algorithm"

using namespace std;

const int N = 305;
const int INF = 9999999;
int n;
int sum[N];
int dp[N][N];

int main(){
    cin>>n;
    for(int i = 1; i <=n; i++) {
      cin>>sum[i];
      sum[i]+=sum[i-1];
    }
    
    for(int len = 2; len <=n; len++) {
      for(int left = 1; left+len-1<=n; left++) {
        int right = left+len-1;
        dp[left][right] = INF;
        for(int k = left; k <right; k++) {
          dp[left][right] = min(dp[left][right],dp[left][k]+dp[k+1][right]+sum[right]-sum[left-1]);
        }
      }
    }
    cout<<dp[1][n]<<endl;

};