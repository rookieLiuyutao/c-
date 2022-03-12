//
// Created by 刘宇韬 on 2022/3/6.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 35;
int n;
int dp[N][N];
//记录每个子区间的根节点
int g[N][N];
int a[N];

void print(int l,int r){
  if (l>r){
    return;
  }
  int root = g[l][r];
  cout<<root<<' ';
  print(l,root-1);
  print(root+1,r);
}

int main(){
  cin>>n;
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
  }
  for(int len = 1; len <=n; len++) {
    for(int l = 1; l+len-1 <=n; l++) {
      int r = l+len-1;
      if (len==1){
        //若某个子树为空，规定其加分为 1。
        //叶子的加分就是叶节点本身的分数，不考虑它的空子树。
        dp[l][r] = a[l];
        g[l][r] = l;
      }else{
        for(int k = l; k <r; k++) {
          //要考虑空节点
          int left = k==l?1:dp[l][k-1];
          int right = k==r?1:dp[k+1][r];
          int score = left*right+a[k];
          if (score>dp[l][r]){
            dp[l][r] = score;
            g[l][r] = k;
          }
        }
      }
    }
  }
  cout<<dp[1][n]<<endl;
  print(1,n);
}    