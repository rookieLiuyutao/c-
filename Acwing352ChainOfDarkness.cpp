  //
  // Created by 刘宇韬 on 2022/3/16.
  //
  #include <iostream>
  #include <cstring>
  #include <algorithm>
  using namespace std;
  const int N = 100005,M = N*2;
  int h[N], e[M], ne[M], idx;
  int fa[N][16], depth[N],q[N],dis[N];
  int cnt[N];
  int n,m;
  int ans;
  void add(int a, int b)  // 添加一条边a->b，边权为c
  {
    e[idx] = b,  ne[idx] = h[a], h[a] = idx ++ ;
  }

  int dfs(int u,int p)
  {
    int res = cnt[u];
    for(int i=h[u];~i;i=ne[i])
    {
      int j=e[i];
      if(j== p) continue;

      int s = dfs(j,u);
      //s==0表示没有与附加边连成环的主边
      //如果这条边断了，那么已经击败d，剩下m条附加边随便砍一条即可，有m种方案
      if (s==0) ans+=m;
      //s==1表示与附加边连成环的环上的一条边
      //如果砍这条边，之后再砍一条非环上的边即可
      else if (s==1) ans++;
      res+=s;
    }
    return res;
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
      int a,b;
      cin>>a>>b;
      add(a,b), add(b,a);
    }
    bfs(1);
    for(int i = 0; i <m; i++) {
      int a,b;
      cin>>a>>b;
      int p = lca(a,b);
      //用差分给a,b间的所有边+1；
      cnt[a]++,cnt[b]++,cnt[p]-=2;

    }
    dfs(1,-1);
    cout<<ans;
  }