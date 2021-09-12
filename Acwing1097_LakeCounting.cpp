/**
 * https://www.luogu.com.cn/problem/P1596
 */

#include "iostream"
#include "queue"

using namespace std;
const int N = 1010;

int n, m;
char g[N][N];
bool st[N][N];

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = t.first - 1; i <= t.first + 1; i++) {
            for (int j = t.second - 1; j <= t.second + 1; j++) {
                if (i == t.first && j == t.second)continue;
                if (i >= n || i < 0 || j >= m || j < 0 || st[i][j] || g[i][j] == '.')continue;
                q.push({i, j});
                st[i][j] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> g[i];
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!st[i][j] && g[i][j] == 'W') {
                bfs(i, j);
                res++;
            }
        }
    }
    cout << res;
}