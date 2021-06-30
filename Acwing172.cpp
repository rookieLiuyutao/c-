//
// Created by 95853 on 2021/6/28.
//

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 510;


struct State {
    int x, y, lie;
};


int n, m;
char g[N][N];
int dist[N][N][3];


bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    return g[x][y] == '#';
}


int bfs(State start, State end) {
    queue<State> q;
    memset(dist, -1, sizeof dist);
    dist[start.x][start.y][start.lie] = 0;
    q.push(start);

    int d[3][4][3] = {
            {{-2, 0, 2}, {0, 1, 1}, {1, 0, 2}, {0, -2, 1}},
            {{-1, 0, 1}, {0, 2, 0}, {1, 0, 1}, {0, -1, 0}},
            {{-1, 0, 0}, {0, 1, 2}, {2, 0, 0}, {0, -1, 2}}
    };

    while (q.size()) {
        auto t = q.front();
        q.pop();
        cout << t.x << " " << t.y << " " << t.lie << endl;
        for (int i = 0; i < 4; i++) {
            State next = {t.x + d[t.lie][i][0], t.y + d[t.lie][i][1], d[t.lie][i][2]};

            int x = next.x, y = next.y;
            if (check(x, y)) continue;
            if (next.lie == 0) {
                if (g[x][y] == 'E') continue;
            } else if (next.lie == 1) {
                if (check(x, y + 1)) continue;
            } else {
                if (check(x + 1, y)) continue;
            }

            if (dist[next.x][next.y][next.lie] == -1) {
                dist[next.x][next.y][next.lie] = dist[t.x][t.y][t.lie] + 1;
                q.push(next);
            }
        }
    }

//    for(int i = 0; i <n; i++) {
//      for(int j = 0; j <m; j++) {
//        for(int k = 0; k <3; k++) {
//          cout<<dist[k][j][k]<<" ";
//        }
//          puts("");
//      }
//        puts("");
//    }

    return dist[end.x][end.y][end.lie];
}


int main() {
    while (scanf("%d%d", &n, &m), n || m) {
        for (int i = 0; i < n; i++) scanf("%s", g[i]);

        State start = {-1}, end;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == 'X' && start.x == -1) {
                    if (g[i + 1][j] == 'X') start = {i, j, 2};
                    else if (g[i][j + 1] == 'X') start = {i, j, 1};
                    else start = {i, j, 0};
                } else if (g[i][j] == 'O') end = {i, j, 0};
        cout << "起点" << start.x << " " << start.y << " " << start.lie << endl;
        cout << "终点" << end.x << " " << end.y << " " << end.lie << endl;

        int res = bfs(start, end);
        if (res == -1) puts("Impossible");
        else printf("%d\n", res);
    }

    return 0;
}
