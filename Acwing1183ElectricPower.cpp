//
// Created by 刘宇韬 on 2022/3/17.
//
#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 30010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int root, ans;

void add(int a, int b)
{
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx ++ ;
}

void tarjan(int u){
  dfn[u] = low[u] = ++ timestamp;
  int cnt = 0;//当前块内 已经可以分出来的子树的个数
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (!dfn[j]) //没有遍历过j
    {
      tarjan(j);
      low[u] = min(low[u], low[j]); //用j更新u
      if (low[j] >= dfn[u])
        cnt++; // j为割点 则多一个连通块
    } else
      low[u] = min(low[u], dfn[j]);
  }
  if (u!=root) cnt++;
  ans = max(ans,cnt);
}

int main() {
  while (cin >> n >> m, n || m) {
    memset(dfn, 0, sizeof dfn);
    memset(h, -1, sizeof h);
    idx = timestamp = 0;

    while (m--) {
      int a, b;
      cin >> a >> b;
      add(a, b), add(b, a);
    }
    ans = 0;
    int cnt = 0;
    for( root = 0; root <n; root++) {
      if (!dfn[root]){
        cnt++;
        tarjan(root);

      }
    }
    cout<<ans+cnt-1<<endl;
  }

}