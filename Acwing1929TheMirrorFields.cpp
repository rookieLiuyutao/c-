#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1010;
int n,m;
char g[N][N];
int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
int dfs(int x,int y,int d){
  if (x<0||x>=n||y<0||y>=m)return 0;
  if (g[x][y] == '/'){
    d^=1;
  }else{
    d^=3;
  }
  return dfs(x+dx[x],y+dy[y],d)+1;
}

int main(){
  cin>>n>>m;
  int res = 0;
  for(int i = 0; i <n; i++) {
    cin>>g[i];
  }
  for(int i = 0; i <n; i++) {
    res = max(res,dfs(i,0,1));
    res = max(res,dfs(i,m-1,3));
  }
  for(int i = 0; i <m; i++) {
    res = max(res,    dfs(0,i,2));
    res = max(res,dfs(0,m-1,0));
  }
  cout<<res;
}