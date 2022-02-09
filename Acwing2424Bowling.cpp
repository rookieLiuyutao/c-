// Created by 95853 on 2022/1/21.
/**
 * https://www.acwing.com/problem/content/2426/
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 55;
#define r first
#define l second
int n, m;
int ans;
PII q[N];

int calc() {
  int res = 0;
  for (int i = 0; i < m; i++) {
    res += q[i].r + q[i].l;
    if (i < n) {
      if (q[i].r == 10) {
        res += q[i + 1].r + q[i + 1].l;
      } else if (q[i].r + q[i].l == 10) {
        res += q[i + 1].r;
      }
    }
  }

  ans = max(res, ans);
  return res;
}

void sa() {
  for (double t = 1e4; t > 1e-4; t *= 0.98) {
    int a = rand() % m, b = rand() % m;
    int p = calc();
    swap(q[a], q[b]);
    if (n + (q[n - 1].r == 10) == m) {
      int u = calc();
      int d = u-p;
      if (exp(d / t) < (double)rand() / RAND_MAX) {
        swap(q[a], q[b]);
      }
    } else {
      swap(q[a], q[b]);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> q[i].r >> q[i].l;
  }
  //看看有没有第n+1轮
  if (q[n - 1].r == 10) {
    m = n + 1;
    cin >> q[n].r >> q[n].l;
  } else {
    m = n;
  }
  for(int i = 0;i<80;i++) {
    sa();
  }
  cout << ans;
}