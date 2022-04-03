//
// Created by 刘宇韬 on 2022/4/3.
//
/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

/**
* https://www.acwing.com/problem/content/description/3552/
* 题目：只能将原序列翻转一次
 * 翻转前的序列必然是：111111111111 22222222222222 11111111111111111 22222222222
 * 共分为4段，每一段的长度都可能为0，显然要翻转
 * 其实可以用4个变量表示4种状态，y总代码详见：
 * https://www.acwing.com/activity/content/code/content/1270205/
 * dp[i][j]表示以第i个为结尾最大上升的序列的长度，第i个字符属于第j段
*/
const int N = 1000005;
int a[N],dp[N][4];
int n;
int main(){
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
  }
  int b[4] = {1,2,1,2};
  for(int i = 1; i <=n; i++) {
    for(int j = 0; j <4; j++) {

      dp[i][j] = dp[i-1][j];
      if (a[i] == b[j]){
        if (j){
          dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
        }
        dp[i][j]++;
      }
    }
  }
  int res = 0;
  for(int i = 0; i <4; i++) {
    res = max(dp[n][i],res);
  }
  cout<<res;
}