//
// Created by 刘宇韬 on 2022/3/19.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100005, M = 2000005;
int n, m;
int hz[N], hf[N], e[M], w[N], ne[M], idx;
int dmax[N], dmin[N];
bool st[N];
int q[N];
void add(int h[], int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }


void spfa(int dis[],int h[],bool type ){
  //type==1正向求最小值
  int hh = 0,tt = 1;
  if (type){
    memset(dis,0x3f,sizeof dmin);
    dis[1] = w[1];
    q[0] = 1;
  }else{
    memset(dis,-0x3f,sizeof dmax);
    dis[n] = w[n];
    q[0] = n;
  }
  while (hh!=tt){
    int t = q[hh++];
    if (hh==N)hh = 0;
    st[t] = false;
    for(int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if (type&&dis[j]> min(dis[t],w[j])||!type&&dis[j]< max(dis[t],w[j])){
        if (type){
          dis[j] = min(dis[t],w[j]);
        }else{
          dis[j] = max(dis[t],w[j]);
        }
        if (!st[j]){
          q[tt++] = j;
          if (tt==N) tt = 0;
          st[j] = true;
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  memset(hz,-1,sizeof hz);
  memset(hf,-1,sizeof hf);

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    //正反向建2个图
    add(hz, a, b), add(hf, b, a);
    if (c == 2) {
      add(hz, b, a), add(hf, a, b);
    }
  }
  spfa(dmin, hz, true);
  spfa(dmax, hf, false);
  int res = 0;
  for(int i = 1; i <=n; i++) {
    res = max(res,dmax[i]-dmin[i]);
  }
  cout<<res;
}