#include "bits/stdc++.h"
using namespace std;
const int N = 55;
char g[N][N];
int n, m;
bool range[N][N];
bool isA = true;

typedef pair<int, int> PII;
vector<PII> qa, qb;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void dfs(int x, int y) {
  //当前点也是符合要求的，应该加进块中
  if (isA)
    qa.push_back({x, y});
  else
    qb.push_back({x, y});

  for (int i = 0; i < 4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 'X' && !range[a][b]) {
      range[a][b] = true;

      dfs(a, b);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < m; j++) {
  //       cout << g[i][j]<<' ';
  //     }
  //     cout<<endl;
  //   }

  int res = 0x3f3f3f3f;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!range[i][j] && g[i][j] == 'X') {
        dfs(i, j);
        isA = false;
      }
    }
  }
  for (auto a : qa) {
    for (auto b : qb) {
      res = min(res, abs(a.first - b.first) + abs(a.second - b.second));
    }
  }
  //   for (auto a : qa)
  //     cout << '(' << a.first << ',' << a.second << ") ";
  //   cout << endl;
  //   for (auto range : qb)
  //     cout << '(' << range.first << ',' << range.second << ") ";
  //   cout << endl;
  cout << res - 1 << endl;
}
