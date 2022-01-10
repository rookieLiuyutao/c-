#include "bits/stdc++.h"

using namespace std;
const int N = 105, M = 2005;

int n, m;
double r;
double o[N], phone[M][N];
//为了减少重复计算，d存每个点到圆心的距离平方，rd存点到圆的切线长的平方
double d[M],rd[M];
//存下每个点到其他点的距离和
double ans[M];

//因为涉及到大量乘方运算，写一个函数减少代码量
inline double sqr(double x) {
    return x * x;
}


int main() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> o[i];
    }
    for (int i = 1; i <= m; i++) {
        double res = 0;
        for (int j = 1; j <= n; j++) {
            cin >> phone[i][j];
            res += sqr(phone[i][j] - o[j]);
        }
        d[i] = res;
        rd[i] =  sqrt(d[i] - sqr(r));
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < i; j++) {

            //算两点间的距离
            double c2 = 0, a = sqrt(d[i]), b = sqrt(d[j]);
            for (int k = 1; k <= n; k++) {
                c2 += sqr(phone[i][k] - phone[j][k]);
            }
            double c = sqrt(c2);
            //算大三角形面积
            double pp = (a + b + c) / 2.0;
            double s = sqrt(pp * (pp - a) * (pp - b) * (pp - c));
            //算高
            double h = 2 * s / c;
            if (h >= r || c2 + d[i] <= d[j] || c2 + d[j] <= d[i]) {
                ans[i] += c;
                ans[j] += c;
                continue;
            }
            //算大三角形顶角
            double angle1 = acos((d[i] + d[j] - c2) / (2 * a * b)),
                    angle2 = acos(r / a), angle3 = acos(r / b);

            //算弧长
            double t = (angle1 - angle2 - angle3) * r + rd[i]+ rd[j];
            ans[i] += t;
            ans[j] += t;
        }

    }
    for (int j = 1; j <= m; j++) {
        printf("%.12f\n", ans[j]);
    }
}

