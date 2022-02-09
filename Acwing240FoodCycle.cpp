//
// Created by 刘宇韬 on 2022/2/5.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 50010;
int p[N],d[N];
int n,m;

int find(int x){
  if (p[x]!=x){
    int t = find(p[x]);
    d[x]+=d[p[x]];
    p[x] = t;
  }
  return p[x];
}

int main(){
  cin>>n>>m;
  for(int i = 1; i <=n; i++) {
    p[i] = i;
  }
  int t,x,y;
  int res = 0;
  while (m--){
    cin>>t>>x>>y;
    if (x>n||y>n){
      res++;
      continue;
    }
    int rx = find(x),ry = find(y);
    if (t==1){
      //rx = ry 表示x，y两个点在一条食物链中
      if (rx==ry&&(d[x]-d[y])%3)res++;
      else if (rx!=ry){
        //x,y不在一个集合里，所以要把2个集合连起来
        p[rx] = ry;
        d[rx] = d[y]-d[x];
      }
    } else{
      if (rx==ry&&(d[x]-d[y]+1)%3==0)res++;
      else if (rx!=ry){
        p[rx] = ry;
        d[rx] = d[y]-d[x]+1;
      }
    }
  }
  cout<<res;
}