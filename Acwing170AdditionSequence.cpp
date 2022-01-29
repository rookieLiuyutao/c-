//
// Created by 95853 on 2022/1/24.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 105;
int n;
int path[N];
bool dfs(int u,int k){
  if (u==k)return path[u-1] == n;
  bool st[N] = {false};
  for(int i = u-1; i >=0; i--) {
    for(int j = i; j >=0; j--) {
      int s = path[i]+path[j];
      if (s>n||s<=path[u-1]||st[s])continue;
      st[s] = true;
      path[u] = s;
      if (dfs(u+1,k)) return true;
    }
  }
  return false;
}

int main(){
  while (cin>>n,n){
    int k = 1;
    while (!dfs(1,k)){
      k++;
    }
    for(int i = 0; i <k; i++) {
      cout<<path[i]<<' ';
    }
    cout<<endl;
  }
}    