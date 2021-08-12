//
// Created by 95853 on 2021/7/24.
//
/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1293
 */
#include "iostream"
using namespace std;
int v[4] = {10,20,50,100};
int m,dp[1010];
int main(){
    int n = 4;
    cin>>m;
    dp[0] = 1;
    while (n--){
        for(int i = 0; i <=m; i++) {
            if (i>=v[n]){
                dp[i] += dp[i-v[n]];
            }
        }
    }
    cout<<dp[m]<<endl;
}