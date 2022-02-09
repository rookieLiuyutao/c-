#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
int dist[N][N], n;
bool g[N][N], range[N][N];
typedef pair<int, int> PII;
deque<PII> q;
#define r first
#define l second
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
//本题把障碍物看成权值为1的点，空地看成权值为0的点，就转换成了最短路问题
//由于只有2种边权，所以可以用双端队列代替djs中的堆
//注意本题说可以走出矩阵的，所以要比1000多搜一点
int bfs(int sx, int sy) {
  q.push_back({sx, sy});
  memset(dist, 0x3f, sizeof dist);
  dist[sx][sy] = 0;

  while (!q.empty()) {
    auto tt = q.front();
    q.pop_front();
    if (range[tt.r][tt.l])
      continue;
    range[tt.r][tt.l] = true;
    if (!tt.r && !tt.l)
      break;
    for (int i = 0; i < 4; i++) {
      int a = tt.r + dx[i], b = tt.l + dy[i];
      if (a < 0 || a > N || b < 0 || b > N)
        continue;
      if (dist[a][b] <= dist[tt.r][tt.l] + g[a][b]) {
        dist[a][b] = dist[tt.r][tt.l] + g[a][b];
        if (!g[tt.r][tt.l]) {
          q.push_front({a, b});
        } else {
          q.push_back({a, b});
        }
      }
    }
  }
  return dist[0][0];
}

int main() {
  int sx, sy, a, b;
  cin >> n >> sx >> sy;
  while (n--) {
    cin >> a >> b;
    g[a][b] = true;
  }
  cout << bfs(sx, sy);
}