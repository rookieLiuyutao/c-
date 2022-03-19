//
// Created by 刘宇韬 on 2022/3/19.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 110;
bool g[N][N];
bool st[N][N];
int n,m,k;
int match[N];

bool dfs(int u  ){
  for
}

int main(){
  while (cin>>n>>m>>k,n||m||k){
    memset(g, false,sizeof g);
    memset(st, false,sizeof st);
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

    cout<<res;
  }
}