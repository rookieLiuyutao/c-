//
// Created by 刘宇韬 on 2022/2/12.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 110;
int n,m;
int h[N],ne[N],e[N*N],w[N*N],idx;
int f[N],u[N];
int din[N],dout[N];
int q[N];
void add (int a,int b,int c){
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx++;
}
void topsort(){
  int hh = 0,tt = -1;
  for(int i = 1; i <=n; i++) {
    if (!din[i]){
      q[++tt] = i;
    }
  }
  while (hh<=tt){
    int t = q[hh++];

    for(int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if ( -- din[j] == 0)
        q[++tt] = j;
      }
    }
  }

}
int main(){
  cin>>n>>m;
  for(int i = 1; i <=n; i++) {
    cin>>f[i]>>u[i];
    //因为最后的值要减去阈值，所以可以提前减去
    if (!f[i])f[i]-=u[i];
  }

  memset(h,-1,sizeof h);

  while (m--){
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c);
    dout[a]++;
    din[b]++;
  }



  topsort();
  //拓扑排序完。队列里的点就是有拓扑序的
  for(int i = 1; i <=n; i++){
    int j = q[i];
    if (f[j]>0){
      for(int k = h[j]; ~k; k = ne[k]) {
        f[e[k]]+=f[j]*w[k];
      }
    }
  }
  bool has_p = false;
//  for(int i = 1; i <=n; i++) {
//    cout<<f[i]<<' ';
//  }
  for(int i = 1; i <=n; i++) {
    if (!dout[i]&&f[i]>0){
      cout<<i<<' '<<f[i]<<endl;
      has_p = true;
    }
  }
  if (!has_p)
    puts("NULL");
}


