/**
 * https://leetcode-cn.com/problems/nearest-exit-from-entrance-in-maze/
 */
#include "bits/stdc++.h"

using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int n = maze.size(), m = maze[0].size(), INF = 1e8;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<PII> q;
    dist[entrance[0]][entrance[1]] = 0;
    q.push({entrance[0],entrance[1]});
    while (!q.empty()) {
        auto tt = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = tt.x + dx[i];
            int b = tt.y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && maze[a][b] == '.' && dist[a][b] > dist[tt.x][tt.y]) {
                dist[a][b] = dist[tt.x][tt.y] + 1;
                if (a == 0 || a == n - 1 || b == 0 || b == m - 1) {
                    return dist[a][b];
                }
                q.push({a, b});
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<char>> maze = {{'+', '+', '.', '+'},
                                 {'.', '.', '.', '+'},
                                 {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};
    cout<<nearestExit(maze,entrance)<<endl;
}