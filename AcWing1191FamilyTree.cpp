//
// Created by 刘宇韬 on 2022/3/20.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100005, M = 2000005;
int n;
int h[N], e[M], w[N], ne[M], idx;
int din[N];
bool st[N];
int q[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void topsort(){
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
}

int main(){
  cin>>n;
  memset(h,-1,sizeof h);
  for(int i = 1; i <=n; i++) {
    int son;
    while (cin>> son, son){
      add(i,son );
      din[son] ++;
    }
  }
  topsort();
  for(int i = 0; i <n; i++) {
    cout<<q[i]<<' ';
  }
}