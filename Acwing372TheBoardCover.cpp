//
// Created by 刘宇韬 on 2022/3/18.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 100,M = 2*N;
typedef pair<int,int> PII;
#define x first
#define y second
int n,m;
PII match[N][N];

bool g[N][N],st[N][N];
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
bool dfs(int p,int q){
  for(int i = 0; i <4; i++) {
    int a = p +dx[i],b = q +dy[i];
    if (a && a <= n && b && b <= n && !g[a][b] && !st[a][b]){
      st[a][b] = true;
      PII t = match[a][b];
      if (t.x==-1|| dfs(t.x,t.y)){
        match[a][b] = {p,q};
        return true;
      }
    }

  }
  return false;
}

int main(){
  cin>>n>>m;
  for(int i = 0; i <m; i++) {
    int a,b;
    cin>>a>>b;
    g[a][b] = true;
  }
  memset(match,-1,sizeof match);
  int res = 0;
  for(int i = 1; i <=n; i++) {
    for(int j = 1; j <=n; j++) {
      if ((i+j)%2&&!g[i][j]){
        memset(st, false,sizeof st);
        if (dfs(i,j)) res++;
      }
    }
  }
  cout<<res;
}