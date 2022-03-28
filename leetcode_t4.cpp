//
// Created by 刘宇韬 on 2022/3/27.
//
/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int m) {
    int n = piles.size();
    vector<int>dp(m+1,-1e9);
    dp[0]= 0;
    for(int i = 0; i <n; i++) {
      int len = piles[i].size();
      //求当前该栈总共取出的物品数量
      vector<int> sum(len+1);
      for(int j = 0; j <len; j++) {
        sum[j+1] = piles[i][j]+ sum[j];
      }
      for(int j = 0; j<m; j++) {
        for(int k = 1; k <=len&&k<=m-j; k++) {
          dp[j+k] = max(dp[j+k],dp[j]+ sum[k]);
        }
      }
    }
    return dp[m];
  }
};