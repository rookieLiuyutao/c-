//
// Created by 刘宇韬 on 2022/3/15.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 100010,M = 3*N;
typedef long long LL;
int h[N],w[M],ne[M],e[M],idx;

int q[N],cnt[N],dis[N];
bool st[N];

int n,m;

void add(int a,int b,int c){
  e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

bool spfa(){
  memset(dis,-0x3f,sizeof dis);
  int hh= 0,tt = 1;
  dis[0] = 0;
  q[0] = 0;
  while(hh!=tt){
    int t = q[--tt];
    st[t] = false;
    for(int i = h[t];~i;i = ne[i]){
      int j = e[i];
      if(dis[j]<dis[t]+w[i]){
        dis[j] = dis[t]+w[i];
        cnt[j] =cnt[t]+1;
        if(cnt[j]>=n+1)return true;
        if(!st[j]){
          st[j] = true;
          q[tt++] = j;
        }
      }


    }
  }
  return false;
}

int main(){
  cin>>n>>m;
  memset(h,-1,sizeof h);
  for(int i = 1;i<=n;i++) add(0,i,1);

  while(m--){
    int x,a,b;
    cin>>x>>a>>b;
    if(x==1) add(a,b,0),add(b,a,0);
    else if(x==2) add(a,b,1);
    else if(x==3) add(b,a,0);
    else if(x==4) add(b,a,1);
    else if(x==5) add(a,b,0);

  }
  if(spfa() ) puts("-1");
  else{
    LL res = 0;
    for(int i = 1;i<=n;i++)res+=dis[i];
    cout<<res;
  }
}
