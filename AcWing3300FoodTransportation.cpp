//
// Created by 刘宇韬 on 2022/3/6.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 105,M = 10,S = 1<<M;
typedef pair<int,int> PII;
#define x first
#define y second
int n,m,k;
//存第n个点需要那些食材
int need[N][M];
//每个酒店需要食材的状态压缩
int state[N];
int h[N], e[N*2], ne[N*2],w[N*2], idx;
//预处理从每辆车从不同检查点出发，且能送完所有食材的最短路长
int dis[M][N];
//预处理的状态数组
int dp[S];
void add(int a, int b,int c)  // 添加一条边a->b
{
  e[idx] = b, w[idx] = c; ne[idx] = h[a], h[a] = idx ++ ;
}
/**
 * 先假设车一定要回到起点，那么它一定要走所有变的2倍，如果它能停在某个点，再用总距离减去那个最远距离
 * @param u 表示以当前遍历的酒店
 * @param p 表示当前点的父节点，引入p的目的是因为图都是双向的边，为了避免遍历根节点u的子节点时算上父节点
 * @param v 表示当前运送的食材
 * @return res.x 表示从起点送完所有食材再回到起点的距离之和，res.y表示与起点距离最远的一个需要食材的点
 */
PII dfs(int u,int p,int v){
  //开始距离距离和为0，距根节点距离为-1；
  PII res (0,-1);
  //如果当前酒店需要这个菜
  if (need[u][v])res.y = 0;
  for(int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    //防止重复遍历到父节点
    if (j== p) continue;
    auto t = dfs(j,u,v);
    if (t.y!=-1){
      res.x+=t.x+w[i]*2;
      res.y = max(res.y,t.y+w[i]);
    }
  }
  return res;
}

bool check(int mid){
  memset(state,0,sizeof state);
  for(int i = 1; i <=n; i++) {
    for(int j = 0; j <k; j++) {
      if (dis[i][j]<=mid){
        state[i] |= 1<<j;
      }
    }
  }
  memset(dp,0x3f,sizeof dp);
  dp[0] = 0;
  for(int i = 0; i <1<<k; i++) {
    for(int j = 1; j <=n; j++) {
      dp[i|state[j]] = min(dp[i|state[j]],dp[i]+1);
    }
  }
  return dp[(1<<k)-1]<=m;
}

int main(){
  memset(h,-1,sizeof h);
  cin>>n>>m>>k;
  for(int i = 1; i <=n; i++) {
    for(int j = 0; j <k; j++) {
      cin>>need[i][j];
    }
  }
  for(int i = 0; i <m; i++) {
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c);
    add(b,a,c);
  }
  //枚举所有酒店
  for(int i = 1; i <=n; i++) {
    for(int j = 0; j <k; j++) {
      auto t = dfs(i,-1,j);
      //它能停在(i,j)，再用总距离减去那个最远距离
      if (t.y!=-1)dis[i][j] = t.x-t.y;
    }
  }
  //二分答案
  int l = 0,r = 2e8;
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