/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1376
 */
#include "bits/stdc++.h"

using namespace std;
const int N = 105, INF = 0x3f3f3f;
int g[N][N], n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i <=n; i++) {
      for(int j = 1; j <=n; j++) {
          if (i==j)g[i][j] = 0;
          else g[i][j] = INF;
      }
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b]  = g[b][a] = min(g[a][b], c);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int res = -1;
    for(int i = 1; i <=n; i++) {
        if (g[i][n]<INF)res = max(res,g[1][i]);
    }
    cout<<res;
}
