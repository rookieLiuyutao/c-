//
// Created by 刘宇韬 on 2022/3/14.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 15;
int n;
// f[i, j]表示一共有i位，且最高位填j的数的个数
int dp[N][N];

int work(int n){
  if (n==0) return 1;
  vector<int >s;
  while (n){
    s.push_back(n%10);
    n/=10;
  }
  int res = 0;
  int last = 0;

  for(int i = s.size()-1; i >=0; i--) {
    int &x = s[i];
    //枚举当前位的下一位填什么
    for(int j = last; j <x; j++) {
      res+=dp[i+1][j];
    }
    if (last>x) break;
    last = x;
    if (i==0) res++;
  }
  return res;

}

int main(){
  for(int i = 0; i <=9; i++) {
    dp[1][i] = 1;
  }
  //枚举每一位
  for(int i = 2; i <N; i++) {
    //枚举能填的所有数
    for(int j = 0; j <=9; j++) {
      //枚举j下一位能填的数
      for(int k = j; k <=9; k++) {
        dp[i][j]+=dp[i-1][k];
      }
    }
  }
  int n,m;
  while (cin>>n>>m){
    cout<<work(m)- work(n-1)<<endl;
  }
}
