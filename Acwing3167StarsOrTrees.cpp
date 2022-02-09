//
// Created by yutaoliu on 2022/1/21.
//
/**
 * https://www.acwing.com/problem/content/3170/
 */
#include "bits/stdc++.h"
#include "random"
using namespace std;
typedef long long LL;
const int N = 110;
typedef pair<double, double> PDD;
#define r first
#define l second
PDD q[N];
double ans = 1e8;
int n;
//产生一定范围随机数的通用表示公式
//    要取得[a,range)的随机整数，使用(rand() % (range-a))+ a;
//要取得[a,range]的随机整数，使用(rand() % (range-a+1))+ a;
//要取得(a,range]的随机整数，使用(rand() % (range-a))+ a + 1;
//要取得(a,range)的随机整数，使用(rand() % (range-a))+ a ;
//通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
//要取得a到b之间的随机整数，另一种表示：a + (int)range * rand() / (RAND_MAX + 1)。
//要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
double rand(double l, double r) {
  return (double)rand() / RAND_MAX * (r - l) + l;
}

double get_dist(PDD a, PDD b) {
  double dx = a.r - b.r;
  double dy = a.l - b.l;
  return sqrt(dx * dx + dy * dy);
}

/**
 * 计算当前点到其他所有点的距离
 * @param p
 * @return
 */
double calc(PDD p) {
  double res = 0;
  for (int i = 0; i < n; i++) {
    res += get_dist(p, q[i]);
  }
  ans = min(ans,res);
  return res;
}
void sa() {
  PDD cur = {rand(0, 10000), rand(0, 10000)};
  for (double t = 1e4; t > 1e-4; t *= 0.9) {
    PDD np = {rand(max(0.0,cur.r - t), cur.r + t), rand(max(0.0,cur.l - t), cur.l + t)};
    double dt = calc(np)- calc(cur);
    if (exp(-dt/t)> rand(0,1)){
      cur = np;
    }

  }
}
int main() {
  cin >> n;
  for(int i = 0; i <n; i++) {
    cin>>q[i].r >>q[i].l;
  }
  for(int i = 0; i <100; i++) {
    sa();
  }
  printf("%.0lf",ans);
}