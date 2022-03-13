//
// Created by 刘宇韬 on 2022/3/13.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 10010,M = 2*N,INF = 0x3f3f3f3f;
int n,m;
int h[N],e[M],ne[M],w[M],idx;

int dp[N][N];

void add(int a,int b,int c){
  e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

void dfs(int u,int fa){
  for(int i = h[u]; i !=-1; i = ne[i]) {
    //因为是双向边，所以一定会枚举到父节点，要过滤掉
    if (e[i]==fa)continue;
    dfs(e[i],u);
    //要选择子树中权重和最小的子树减掉
    for(int j = m; j >0; j--) {
      for(int k = 0; k + 1<=j; k++) {
        dp[u][j] = max(dp[u][j],dp[u][j-k-1]+dp[e[i]][k]+w[i]);
      }
    }
  }

}

int main(){
  cin>>n>>m;
  memset(h,-1,sizeof h);
  for(int i = 0; i <n-1; i++) {
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c),add(b,a,c);
  }
  dfs(1,-1);
  cout<<dp[1][m]<<endl;
}