//
// Created by 刘宇韬 on 2022/3/15.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1005,M = 200010;
typedef long long LL;
int h[N],w[M],ne[M],e[M],idx;

int q[N],cnt[N],dis[N];
bool st[N];
int n,m1,m2;


void add(int a,int b,int c){
  e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

bool spfa(int size){

  memset(dis,0x3f,sizeof dis);
  memset(st,0,sizeof st);
  memset(cnt,0,sizeof cnt);
  int hh= 0,tt = 0;
  for(int i = 1; i <= size; i++) {
    dis[i] = 0;
    q[tt++] = i;
    st[i] = true;
  }
  while(hh!=tt){
    int t = q[hh++];
    if (hh == N) hh = 0;
    st[t] = false;
    for(int i = h[t];~i;i = ne[i]){
      int j = e[i];
      if(dis[j]>dis[t]+w[i]){
        dis[j] = dis[t]+w[i];
        cnt[j] =cnt[t]+1;
        if(cnt[j]>= n )return true;
        if(!st[j]){
          q[tt++] = j;
          if (tt == N) tt = 0;
          st[j] = true;
        }
      }
    }
  }
  return false;
}

int main(){

  cin>>n>>m1>>m2;
  memset(h,-1,sizeof h);
  for(int i = 1;i<n;i++) add(i+1,i,0);

  while(m1--){
    int a,b,c;
    cin>>a>>b>>c;
    if (a>b)
      swap(a,b);
    add(a,b,c);

  }
  while (m2--){
    int a,b,c;
    cin>>a>>b>>c;
    if (a>b)
      swap(a,b);
    add(b,a,-c);
  }
  if(spfa(n) ) puts("-1");
  else{
    spfa(1);
    if (dis[n]==0x3f3f3f3f)
      puts("-2");
    else cout<<dis[n];
  }
//   for(int i = 0; i <=n; i++) {
//     cout<<dis[i]<<' ';
//   }
}
