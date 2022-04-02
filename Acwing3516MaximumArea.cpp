/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
#include "queue"
#include "unordered_map"
#include "unordered_set"
#include "vector"
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define pb push_back
#define fi first
#define se second
const int N = 2005;
int n, m;
char g[N][N];
int l[N], r[N], q[N];
int U[N], D[N], L[N], R[N];
int s[N][N];

int calc(int h[], int len) {
  int tt = 0;
  q[0] = 0;
  h[0] = h[len + 1] = -1;
  for (int i = 1; i <= len; i++) {
    while (h[i] <= h[q[tt]])
      tt--;
    l[i] = q[tt];
    q[++tt] = i;
  }

  tt = 0;
  q[0] = len + 1;
  for (int i = len; i; i--) {
    while (h[i] <= h[q[tt]])
      tt--;
    r[i] = q[tt];
    q[++tt] = i;
  }

  int res = 0;
  for (int i = 1; i <= len; i++) {
    res = max(h[i] * (r[i] - l[i] - 1), res);
  }
  return res;
}

void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == '1')
        s[i][j] = s[i - 1][j]+1;
      else
        s[i][j] = 0;
    }
    U[i] = max(U[i - 1], calc(s[i], n));
  }
  memset(s, 0, sizeof s);
  for (int i = n; i; i--) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == '1')
        s[i][j] = s[i + 1][j];
      else
        s[i][j] = 0;
    }
    D[i] = max(D[i + 1], calc(s[i], n));
  }
  memset(s, 0, sizeof s);
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (g[i][j] == '1')
        g[i][j] = g[i][j - 1]+1;
      else
        g[i][j] = 0;
    }
    L[j] = max(L[j - 1], calc(s[j], m));
  }
  memset(s, 0, sizeof s);
  for (int j = m; j; j--) {
    for (int i = 1; i <= n; i++) {
      if (g[i][j] == '1')
        s[i][j] = s[i][j + 1]+1;
      else
        s[i][j] = 0;
    }
    R[j] = max(R[j + 1], calc(s[j], m));
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 1; i <=n; i++) {
    for(int j = 1; j <=m; j++) {
      cin>>g[i][j];
    }
  }
  init();
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    x++,y++;
    cout << max(max(U[x - 1], D[x + 1]), max(L[y - 1], R[y + 1])) << endl;
  }
}