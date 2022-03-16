//
// Created by 刘宇韬 on 2022/3/16.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20010,M = N*2;
int h[N], e[M], w[M], ne[M], idx;
int fa[N][16], depth[N],q[N],dis[N];
int n,m;

void add(int a, int b, int c)  // 添加一条边a->b，边权为c
{
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u,int p)
{
  for(int i=h[u];~i;i=ne[i])
  {
    int j=e[i];
    if(j== p) continue;
    dis[j]=dis[u]+w[i];
    dfs(j,u);
  }
}

void bfs(int root)  // 预处理倍增数组
{
  memset(depth, 0x3f, sizeof depth);
  depth[0] = 0, depth[root] = 1;  // depth存储节点所在层数
  int hh = 0, tt = 0;
  q[0] = root;
  while (hh <= tt)
  {
    int t = q[hh ++ ];
    for (int i = h[t]; ~i; i = ne[i])
    {
      int j = e[i];
      if (depth[j] > depth[t] + 1)
      {
        depth[j] = depth[t] + 1;
        q[ ++ tt] = j;
        fa[j][0] = t;  // j的第二次幂个父节点
        for (int k = 1; k <= 15; k ++ )
          fa[j][k] = fa[fa[j][k - 1]][k - 1];
      }
    }
  }
}

int lca(int a, int b)  // 返回a和b的最近公共祖先
{
  if (depth[a] < depth[b]) swap(a, b);
  for (int k = 15; k >= 0; k -- )
    if (depth[fa[a][k]] >= depth[b])
      a = fa[a][k];
  if (a == b) return a;
  for (int k = 15; k >= 0; k -- )
    if (fa[a][k] != fa[b][k])
    {
      a = fa[a][k];
      b = fa[b][k];
    }
  return fa[a][0];
}


int main(){
  cin>>n>>m;
  memset(h,-1,sizeof h);
  for(int i = 0; i <n-1; i++) {
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c), add(b,a,c);
  }
  dfs(1,-1);
  bfs(1);
  while (m--){
    int x,y;
    cin>>x>>y;
    if (x==y)
      puts("0");
    else{
      //通过画图可以发现：树中两个点的距离为，两个点到根节点的距离和减去2倍的根节点到这两个点的最近公共祖先的距离
      int ans =dis[x]+dis[y]-2*dis[lca(x,y)];
      cout<<ans<<endl;
    }

  }

}