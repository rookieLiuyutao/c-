/**
 * https://www.acwing.com/problem/content/1017/
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int n,pass;
int dp[N][N];

int main()
{
    int T;
    cin>>T;
    while (T -- ){
        cin >> n >> pass;
        for (int i = 1; i <= n; i ++ ){
            for (int j = 1; j <= pass; j ++ ){
                cin >> dp[i][j];
            }
        }
        for(int i = n;i>=1;i--){
            for(int j = pass; j >= 1; j--){
                dp[i][j]+=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        cout <<dp[1][1]<<endl;

    }
}