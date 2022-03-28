//
// Created by 刘宇韬 on 2022/3/20.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100005, M = 2000005;
int n,m;
int h[N], e[M], w[N], ne[M], idx;
int din[N];
int dis[N];
int q[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool topsort(){
  int hh= 0,tt = -1;
  for(int i = 1; i <=n; i++) {
    if (din[i]==0) q[++tt] = i;
  }
  while (hh<=tt){
    int t = q[hh++];
    for(int i = h[t]; i !=-1; i = ne[i]) {
      int j = e[i];
      if (--din[j]==0) {
        q[++tt] = j;
      }
    }
  }
  return tt == n - 1;
}

int main(){
  cin>>n>>m;

  memset(h,-1,sizeof h);
  while (m--){
    int a,b;
    cin>>a>>b;
    add(a,b);
  }
  if (!topsort()) {
    puts("Poor Xed");
  }else{
    //每个员工至少花100；
    for(int i = 1; i <=n; i++) {
      dis[i] = 100;
    }
    //根据拓扑序求最长路
    for(int i = 1; i <=n; i++) {
      int j = q[i];
      for(int k = h[j]; ~k; k = ne[k]) {
        dis[e[k]] = max(dis[e[k]],dis[j]+w[i]);
      }
    }
    //将路径的权值累加即为答案
    int res = 0;
    for(int i = 1; i <=n; i++) {
      res+=dis[i];
    }
    cout<<res;

  }


}