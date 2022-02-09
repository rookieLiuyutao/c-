#include "bits/stdc++.h"

using namespace std;
const int N = 18, M = 1 << 18;
const double eps = 1e-8;
#define r first
#define l second
typedef pair<double, double> PDD;
int m, n;
//存题中给的点
PDD q[N];
//path[a][b]表示抛物线y = ax^2+bx 所覆盖的所有点(state)
int path[N][N];
//记录已经被覆盖过的state
int dp[M];

int cmp(double r, double l){
    if ()
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> q[i].r >> q[i].l;
        }
        //因为有多组数据，每次使用前都要清空
        memset(path, 0, sizeof path);
        for (int i = 0; i < n; i++) {
            //
            path[i][i] = 1 << i;
            for(int j = 0; j <n; j++) {
              double x1 = q[i].r,x2 = q[j].r;
              double y1 = q[i].l,y2 = q[j].l;
              //一条抛物线不可能经过2个竖直的点，要判断x1和x2是否相等

              double a = (y1/x1-y2/x2)/(x1-x2);
              double b = (y1-a*x1*x1)/x1;

            }
        }
    }

}

