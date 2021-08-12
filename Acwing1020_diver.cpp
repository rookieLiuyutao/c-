//
// Created by 95853 on 2021/7/24.
//
/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1271
 */
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
const int N = 85;
int n,m,v ,dp[N][N];
int main(){
    cin>>v>>m>>n;
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for(int i = 0; i <n; i++) {
      int a,b,c;
      cin>>a>>b>>c;
      for(int j = v; j >=0; j--) {
        for(int k =m; k >=0; k--) {
          dp[j][k] = min(dp[j][k],dp[max(0,j-a)][max(0,k-b)]+c);
        }
      }
    }
    cout<<dp[v][m]<<endl;


}