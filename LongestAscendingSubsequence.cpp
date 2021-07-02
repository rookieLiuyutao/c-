/**
 * @see 线性dp https://www.acwing.com/problem/content/description/897/
 */

#include "bits/stdc++.h"
using namespace std;
const int N = 1010;
int arr[N],dp[N];
int n;
int main(){
    cin>>n;
    int res = 1;
    for(int i = 0; i <n; i++) {
      cin>>arr[i];
      dp[i] = 1;
      for(int j = 0; j <i; j++) {
          if (arr[j]<arr[i]){
              dp[i] = max(dp[i],dp[j]+1);
          }
      }
      res = max(res,dp[i]);
    }

    cout<<res<<endl;
}