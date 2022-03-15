//
// Created by 刘宇韬 on 2022/3/13.
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1505, M = N, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
// dp[N][0]: 表示在点i不放警卫，且该点能被其父节点观测到，的最小花费
// dp[N][1]: 表示在点i不放警卫，且该点能被其子节点观测到，的最小花费
// dp[N][2]: 表示在点i放警卫，的最小花费
int dp[N][3];
int root;
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u) {

  dp[u][0] = 0;
  dp[u][1] = 1e9; //f[u][1]求最小值，初始化为最大值
  dp[u][2] = w[u];

  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    dfs(j);

    dp[u][0] += min(dp[j][1], dp[j][2]);
    dp[u][2] += min(min(dp[j][0],dp[j][1]),dp[j][2]);
  }
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    dp[u][1] = min(dp[u][1],dp[j][2]+dp[u][0]- min(dp[j][1],dp[j][2]));
  }
}

int main() {
  cin>>n;
  memset(h, -1, sizeof h);
  root = 1;
  for (int i = 0; i < n; i++) {
    int id, cost,cnt;
    cin>>id>>cost>>cnt;
    w[id] = cost;
    while (cnt--) {
      int x;
      cin >> x;
      add(id, x);
      st[x] = true;
    }
  }
  while (st[root])
    root++;
  dfs(root);
  cout << min(dp[root][1], dp[root][2]) << endl;
}