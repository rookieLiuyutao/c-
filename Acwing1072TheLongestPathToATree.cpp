//
// Created by 刘宇韬 on 2022/3/12.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 10010,M = 2*N;
int n;
int h[N],e[M],ne[M],w[M],idx;
int res;

void add(int a,int b,int c){
  e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

int dfs(int u,int fa){
  int dis = 0;
  int d1 = 0,d2 = 0;
  for(int i = h[u]; i !=-1; i = ne[i]) {
    int j = e[i];
    if (j==fa) continue;
    int d = dfs(j,u)+w[i];
    dis = max(dis,d);
    if (d>=d1)d2 = d1,d1 = d;
    else if (d>d2)d2 = d;
  }
  res = max(d1+d2,res);
  return dis;
}

int main(){
  cin>>n;
  memset(h,-1,sizeof h);
  for(int i = 0; i <n-1; i++) {
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c),add(b,a,c);
  }
  dfs(1,-1);
  cout<<res<<endl;
}