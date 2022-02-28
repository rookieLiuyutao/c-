//
// Created by 刘宇韬 on 2022/2/26.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 505, M = 200005;
typedef pair<int, int> PII;
//表示距离，点编号，最后一条小路长度
typedef pair<int, PII> PIP;
#define x first
#define y second
int n, m;
int h[N], e[M], ne[M], w[M], p[M], idx;

//保证答案不超过 10e6,说明连续小路的长度不超过1000；
// dis[i][j]表示从起点走到i，且最后一段小路长是j的疲惫值;
int dis[N][1010];

void add(int a, int b, int c, int t) {
  e[idx] = b;
  w[idx] = c;
  p[idx] = t;
  ne[idx] = h[a];
  h[a] = idx++;
}

void djs() {
  priority_queue<PIP, vector<PIP>, greater<PIP>> q;
  memset(dis, 0x3f, sizeof dis);
  dis[1][0] = 0;
  //表示距离，点编号，最后一条小路长度
  q.push({0, {1, 0}});
  while (!q.empty()) {
    auto t = q.top();
    q.pop();
    int hp = t.x, id = t.y.x, len = t.y.y;
    for (int i = h[id]; ~i; i = ne[i]) {
      int j = e[i];
      //其中 t 为 0 表示大道，t 为 1 表示小道。
      if (p[j]) {
        int after = len + w[i];
        if (after <= 1000) {
          if (dis[j][after] > hp - len * len + (after * after)) {
            dis[j][after] = hp - len * len + (after * after);
            if (dis[j][after] <= 1e6) {
              q.push({dis[j][after], {j, after}});
            }
          }
        }

      } else {
        if (dis[j][0] > hp + w[i]) {
          dis[j][0] = hp + w[i];
          if (dis[j][0] <= 1e6)
            q.push({dis[j][0], {j, 0}});
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while (m--) {
    int t, a, b, c;
    cin >> t >> a >> b >> c;
    add(a, b, c, t);
    add(b, a, c, t);
  }
  djs();
  int res = 1e6;
  for (int i = 0; i <= 1000; i++) {
//    cout << dis[n][i]<<' ';
    res = min(res, dis[n][i]);
  }
  cout << res;
}