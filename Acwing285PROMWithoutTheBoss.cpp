//
// Created by 刘宇韬 on 2022/3/13.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 6005 ,M = N,INF = 0x3f3f3f3f;
int n,m;
int h[N],e[M],ne[M],w[M],idx;
bool st[N];
//表示以u为根节点的子树是否选择当前根节点
int dp[N][2];
int root = 1;
void add(int a,int b){
  e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void dfs(int u){
  //如果选当前根节点，就加上这个点的权值
  dp[u][1] = w[u];
  for(int i = h[u]; i !=-1; i = ne[i]) {
    int j = e[i];
    dfs(j);
    //如果不选当前根节点,他的子节点可选可不选，从中挑一个权值大的
    dp[u][0] += max(dp[j][1],dp[j][0]);
    //如果选了当前根节点，就一定不选他的子节点
    dp[u][1] += dp[j][0];
  }

}

int main(){
  cin>>n;
  memset(h,-1,sizeof h);
  for(int i = 1; i <=n; i++) {
    cin>>w[i];
  }
  for(int i = 0; i <n-1; i++) {
    int l,k;
    cin>>l>>k;
    st[l] = true;
    add(k,l);
  }
  while (st[root]&&root<=n)root++;
  dfs(root);
  cout<<max(dp[root][0],dp[root][1])<<endl;
}