//
// Created by 刘宇韬 on 2022/3/15.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 50010,M = 3*N;
typedef long long LL;
int h[N],w[M],ne[M],e[M],idx;

int q[N],cnt[N],dis[N];
bool st[N];



void add(int a,int b,int c){
  e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

void spfa(){
  memset(dis,-0x3f,sizeof dis);
  int hh= 0,tt = 1;
  dis[0] = 0;
  q[0] = 0;
  st[0] = true;
  while(hh!=tt){
    int t = q[hh++];
    if (hh == N) hh = 0;
    st[t] = false;
    for(int i = h[t];~i;i = ne[i]){
      int j = e[i];
      if(dis[j]<dis[t]+w[i]){
        dis[j] = dis[t]+w[i];
        if(!st[j]){
          q[tt++] = j;
          if (tt==N) tt = 0;
          st[j] = true;
        }
      }
    }
  }
}

int main(){
  int m;
  cin>>m;
  memset(h,-1,sizeof h);
  for(int i = 1; i <N; i++) {
    add(i-1,i,0);
    add(i, i - 1, -1);
  }

  while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b+1,c);
  }
  spfa();
  cout<<dis[50001];
}

