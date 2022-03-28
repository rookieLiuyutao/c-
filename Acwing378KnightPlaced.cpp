//
// Created by 刘宇韬 on 2022/3/19.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 110;
int g[N][N];
PII match[N][N];
bool st[N][N];
int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
int n, m, k;

bool dfs(PII u) {
  for (int i = 0; i < 8; i++) {
    int a = u.x + dx[i], b = u.y + dy[i];
    if (a < 0 || a >= n || b < 0 || b >= n || g[a][b])
      continue;
    PII next = {a, b};
    if (!st[a][b] || dfs(match[a][b])) {
      st[a][b] = true;
      match[a][b] = next;
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b] = true;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i + j) % 2 || g[i][j])
        continue;
      PII u = {i, j};
      memset(st, 0, sizeof st);
      if (dfs(u))
        res++;
    }
  }
  cout << n * m - k - res;
}