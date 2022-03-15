//
// Created by 刘宇韬 on 2022/3/14.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 11;
//考虑前i位且第i位上的数子位j
int dp[N][N];
int l,r;

int work(int n){
  if (n==0) return 0;
  vector<int >s;
  while (n) {
    s.push_back(n%10);
    n/=10;
  }
  int res = 0;
  //last 表示当前位的上一位，因为初始枚举的最高位，最高位可以从1开始，要初始化成符合要求的数，即为<=-1的数
  int last = -1;
  for(int i = s.size()-1; i >=0; i--) {
    int &x = s[i];
    //最高位不能是0，其他位都可以
    for(int j =  i == s.size() - 1; j <x; j++) {
      if (abs(j-last)>=2){
        res+=dp[i+1][j];
      }
    }
    if (abs(x-last)>=2) last = x;
    //如果当前位不合法，说明当前分支要抛弃
    else break;
    if (i==0) res++;
  }
  for(int i = 1; i <s.size(); i++) {
    for(int j = 1; j <=9; j++) {
      res+=dp[i][j];
    }
  }
  return res;
}
int main(){
  cin>>l>>r;
  //所有1位数都符合要求
  for(int i = 0; i <=9; i++) {
    dp[1][i] = 1;
  }
  for(int i = 2; i <N; i++) {
    for(int j = 0; j <=9; j++) {
      //以第i位的下一位作为划分
      for(int k = 0; k <=9; k++) {
        if (abs(j-k)>=2){
          dp[i][j] +=dp[i-1][k];
        }
      }
    }
  }

  cout<<work(r)- work(l-1)<<endl;
}    