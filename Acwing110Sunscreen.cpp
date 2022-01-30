//
// Created by 95853 on 2022/1/30.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 2505;
int n, m;
PII range[N];
int cover[N], spf[N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> range[i].x >> range[i].y;
  }
  for (int i = 0; i < m; i++) {
    cin >> spf[i] >> cover[i];
  }

}