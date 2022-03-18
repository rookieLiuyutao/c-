//
// Created by 刘宇韬 on 2022/3/18.
//
#include <bits/stdc++.h>

using namespace std;

const int N = 20010, M = 100010;
int n, m;
int h[N], e[M], ne[M], w[M],idx;
int colors[N];

void add(int a, int b,int c)
{
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx ++ ;
}

bool dfs(int u,int color,int mid){
  colors[u] = color;
  for(int i = h[u]; i !=-1; i = ne[i]) {
    int j = e[i];
    if (w[i]<=mid) continue;
    if (colors[j]){
      if (colors[j]==colors[u]) return false;
    }else if (!dfs(j,3-color,mid)){
      return false;
    }
  }
  return true;
}

bool check(int mid){
  memset(colors,0,sizeof colors);
  for(int i = 1; i <=n; i++) {
    if (!colors[i]){
      if (!dfs(i,1,mid)){
        return false;
      }
    }
  }
  return true;
}
int main(){
  cin>>n>>m;
  memset(h,-1,sizeof h);
  while (m--){
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c), add(b,a,c);
  }

  int l = 0,r = 1e9;
  while (l<r){
    int mid = (l+r)>>1;
    if (check(mid)){
      r = mid;
    }else{
      l = mid+1;
    }
  }
  cout<<r;
}