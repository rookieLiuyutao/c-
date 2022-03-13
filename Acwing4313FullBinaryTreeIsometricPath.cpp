//
// Created by 刘宇韬 on 2022/3/13.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = (1<<10)+5;
int w[N];
int n,res;

int dfs(int u){
  if (u*2>(1<<(n+1))-1){
    return res;
  }
  int l = dfs(u*2)+w[u*2];
  int r = dfs(u*2+1)+w[u*2+1];
  res+= abs(l-r);
  return max(l,r);
}

int main(){
  cin>>n;
  for(int i = 2; i <=(1<<(n+1))-1; i++) {
    cin>>w[i];
  }
  dfs(1);
  cout<<res;
}    