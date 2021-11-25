/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1344
 */
#include "bits/stdc++.h"

using namespace std;
const int N = 2010;
int n, m;
double g[N][N], dis[N];
bool st[N];

void djs(int s) {
    dis[s] = 1;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            while (!st[j] && (t == -1 || dis[t] < dis[j]))t = j;
        }
        if (t == n)break;
        st[t] = true;
        for (int j = 1; j <= n; j++) {
            dis[j] = max(dis[j], dis[t] * g[t][j]);
        }
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        double money = (100.0 - c) / 100;
        g[a][b] = g[b][a] = max(g[a][b], money);
    }
    int start, end;
    cin >> start >> end;
    djs(start);
    printf("%.8f", 100 / dis[end]);
}
