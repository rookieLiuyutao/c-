//
// Created by 95853 on 2021/8/21.
//

#include "iostream"
using namespace std;
const int N = 10010;
int dp[N];
int main(){
    int n,m;
    cin>>n>>m;
    dp[0] = 1;
    for(int i = 0; i <n; i++) {
      int v;
      cin>>v;
      for(int j = v;j<=m;j++){
          dp[j]+=dp[j-v];
      }
    }
    cout<<dp[m]<<endl;
}