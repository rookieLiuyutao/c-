//
// Created by 刘宇韬 on 2022/3/13.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 50010;
int n;
int s[N];
int e[N],ne[N],h[N],idx;
bool st[N];
void add(int a,int b){
  e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
int res;
int dfs(int u){
  st[u] = true;
  int dis = 0;
  int d1 = 0,d2 = 0;
  for(int i = h[u]; i !=-1; i=ne[i]) {
    int j = e[i];
    if (!st[j]){
      int d = dfs(j);
      dis = max(dis,d);
      if (d>=d1)d2 = d1,d1 = d;
      else if (d>d2) d2 = d;
    }
  }
  res = max(d1+d2,res);
  return dis;
}

int main(){
  cin>>n;
  for(int i = 1; i <=n; i++) {
    for(int j = 2; j <=n/i; j++) {
      s[i*j] +=i;
    }
  }
  memset(h,-1,sizeof h);
  
  for(int i = 2; i <=n; i++) {
    if (s[i]<i){
      add(s[i],i);
    }
  }
  for(int i = 1; i <=n; i++) {
    if (!st[i]){
      dfs(i);
    }
  }

  cout<<res;
}    