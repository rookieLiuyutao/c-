//
// Created by 95853 on 2022/1/30.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define r first
#define l second
const int N = 2505;
int n, m;
PII range[N],spf[N];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)cin >> range[i].r >> range[i].l;
  for (int i = 0; i < m; i++)cin>>spf[i].r >>spf[i].l;
  sort(range, range + n);
  sort(spf,spf+m);
  int res = 0;
  for (int i = n-1;i>=0;i--) {
    for(int j = m-1; j >=0; j--) {
      if (spf[j].r <= range[i].l && spf[j].r >= range[i].r && spf[j].l) {
        res++;
        spf[j].l--;
        break;
      }
    }
  }
  cout<<res;
}