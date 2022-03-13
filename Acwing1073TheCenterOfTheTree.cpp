//
// Created by 刘宇韬 on 2022/3/12.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 10010,M = 2*N,INF = 0x3f3f3f3f;
int n;
int h[N],e[M],ne[M],w[M],idx;
//d1,d2,分别存每个节点向下走的最长和次长距离
int d1[N],d2[N],up[N];
//存最长路径向下哪个节点走了
int p1[N];


void add(int a,int b,int c){
  e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

int dfsd(int u,int fa){
  //将当前节点向下走的最长和次长距离初始化为负无穷
  d1[u] = d2[u] = -INF;
  for(int i = h[u]; i !=-1; i = ne[i]) {
    int j = e[i];
    if (j==fa)continue;
    int d = dfsd(j,u)+w[i];
    if (d>=d1[u]){
      d2[u] = d1[u],d1[u] = d;
      p1[u] = j;
    }else if (d>d2[u]){
      d2[u] = d;
    }
  }
  if (d1[u] == -INF) d1[u] = d2[u] = 0; //特判叶子结点
  return d1[u];
}


void dfsu(int u, int fa) {
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (j == fa)
      continue;
    if (p1[u] == j)
      up[j] = max(up[u], d2[u]) + w[i];
    else
      up[j] = max(up[u], d1[u]) + w[i];
    dfsu(j, u);
  }
}


int main(){
  cin>>n;
  memset(h,-1,sizeof h);
  for(int i = 0; i <n-1; i++) {
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c),add(b,a,c);
  }
  dfsd(1,-1);
  dfsu(1,-1);
  int res = INF;
  for (int i = 1; i <= n; i ++ ) res = min(res, max(d1[i], up[i]));
  cout<<res;
}