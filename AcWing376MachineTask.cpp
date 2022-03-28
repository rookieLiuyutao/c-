//
// Created by 刘宇韬 on 2022/3/19.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 110;
bool g[N][N];
bool st[N];
int n,m,k;
int match[N];

bool dfs(int u  ){
  for(int i = 0; i <m; i++) {
    if (!st[i]&&g[u][i]){
      st[i] = true;
      if(match[i]==-1|| dfs(match[i])){
        match[i] = u;
        return true;
      }
    }
  }
  return false;
}

int main(){
  while (cin>>n>>m>>k,n){
    memset(g, 0,sizeof g);
    memset(match, -1, sizeof match);

    //读入每个任务
    for(int i = 0; i <k; i++) {
      int c,a,b;
      cin>>c>>a>>b;
      //因为2台机器初始都在模式0，所以用到0的任务不用后续处理
      if (a==0||b==0 )continue;
      //表示a->b有一条边
      g[a][b] = true;
    }
    int res=  0;

    for(int i = 0 ; i <n; i++) {
      memset(st,0,sizeof st);
      if (dfs(i))res++;
    }
    cout<<res;
  }
}