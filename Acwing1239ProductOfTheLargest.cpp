//
// Created by 刘宇韬 on 2022/4/7.
//
/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, bool> PIB;
#define pb push_back
#define fi first
#define se second
/**
 * https://www.acwing.com/problem/content/1241/
 * 贪心
 * 负数必然是成对选
 * 如果k是偶数，正数和负数都成对选
 * 如果k是奇数，那么先选一个最大最大整数，然后正数和负数都成对选
 */
const int N = 100010, MOD = 1000000009;
int a[N];

int n, m;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sign = 1;
  sort(a, a + n);
  LL res = 1;
  int l = 0, r = n - 1;
  if (m % 2) {
    res = a[r--];
    m--;
    if (res < 0)
      sign = -1;
  }
  while (m) {
    LL x = (LL)a[l] * a[l + 1], y = (LL)a[r] * a[r - 1];
    if (x * sign < y * sign) {
      res = y % MOD * res % MOD;
      r -= 2;
    } else {
      res = x % MOD * res % MOD;
      l += 2;
    }
    m -= 2;
  }
  cout << res;
}