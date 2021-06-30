/**
 * @see 广搜  https://www.acwing.com/problem/content/174/
 */
#include "cstring"
#include "algorithm"
#include "queue"
#include "iostream"
#include "cstdlib"

using namespace std;
struct State {
    //line为长方体的状态，0：立着；1：横着躺，2：竖着躺
    int x, y, line;
};

const int N = 510;
int n, m;
char g[N][N];
int dist[N][N][3];

bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return true;
    }
    return g[x][y] == '#';

}

//从起始的3种状态，4个方向，操作后的状态
int d[3][4][3] = {
        {{-2, 0, 2}, {0, 1, 1}, {1, 0, 2}, {0, -2, 1}},
        {{-1, 0, 1}, {0, 2, 0}, {1, 0, 1}, {0, -1, 0}},
        {{-1, 0, 0}, {0, 1, 2}, {2, 0, 0}, {0, -1, 2}}
};

int bfs(State start, State end) {
    queue<State> queue;
    memset(dist, -1, sizeof dist);
    dist[start.x][start.y][start.line] = 0;
    queue.push(start);
    while (!queue.empty()) {
        auto t = queue.front();
        queue.pop();

        for (int i = 0; i < 4; i++) {
            State next = {t.x + d[t.line][i][0], t.y + d[t.line][i][1], d[t.line][i][2]};
            int x = next.x;
            int y = next.y;
            int line = next.line;
            if (check(x, y)) continue;
            if (line == 0) {
                if (g[x][y] == 'E') {
                    continue;
                }
            } else if (line == 1) {
                if (check(x, y + 1)) {
                    continue;
                }
            } else {
                if (check(x + 1, y)) {
                    continue;
                }
            }
            if (dist[x][y][line] == -1) {
                dist[x][y][line] = dist[t.x][t.y][t.line] + 1;
                queue.push(next);
            }
        }
    }
    return dist[end.x][end.y][end.line];

}


int main() {
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        State start = {-1, -1, -1}, end;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'X' && start.x == -1) {
                    if (g[i + 1][j] == 'X') {
                        start = {i, j, 2};
                    } else if (g[i][j + 1] == 'X') {
                        start = {i, j, 1};
                    } else {
                        start = {i, j, 0};
                    }
                } else {
                    if (g[i][j] == 'O') {
                        end = {i, j, 0};
                    }
                }
            }
        }
        int res = bfs(start, end);

        cout << "起点" << start.x << " " << start.y << " " << start.line << endl;
        cout << "终点" << end.x << " " << end.y << " " << end.line << endl;

        if (res == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << res << endl;
        }
    }


}