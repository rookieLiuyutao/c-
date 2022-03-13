//
// Created by 刘宇韬 on 2022/3/13.
//
//
// Created by 刘宇韬 on 2022/3/13.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1505 ,M = N,INF = 0x3f3f3f3f;
int n,m;
int h[N],e[M],ne[M],w[M],idx;
bool st[N];

int dp[N][2];
int root;
void add(int a,int b){
  e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void dfs(int u){
  //如果选当前根节点，就加上这个点的权值
  dp[u][1] = 1;
  dp[u][0] = 0;
  for(int i = h[u]; i !=-1; i = ne[i]) {
    int j = e[i];
    dfs(j);
    //如果选当前边,他的子节点可选可不选，从中挑一个权值大的
    dp[u][1] += min(dp[j][1],dp[j][0]);
    //如果不选当前边，就一定不选他的子节点
    dp[u][0] += dp[j][1];
  }

}

int main(){
  while (scanf("%d",&n)!=-1){
    memset(h,-1,sizeof h),idx = 0;
    memset(st, 0, sizeof st);
    root = 0;
    for(int i = 0; i <n; i++) {
      int id,cnt;
      scanf("%d:(%d)",&id,&cnt);
      while (cnt--){
        int x;
        cin>>x;
        add(id,x);
        st[x] = true;
      }

    }
    while (st[root])root++;
    dfs(root);
    cout<<min(dp[root][0],dp[root][1])<<endl;

  }


}