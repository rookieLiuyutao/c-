#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 500010;
LL n, a[N], t[N];
vector<int> findBall(vector<vector<int>> &g) {
  int n = g.size(), m = g[0].size();
  vector<int> ans(n);
  for (int k = 0; k < n; k++) {
    int p = k;
    for (int i = 0, j = 0; i < n && j < m; i++) {
      if (g[i][j] == -1 && k - 1 >= 0 && i - 1 >= 0 && g[i - 1][j] != 1) {
        p--;
      } else if (g[i][j] == 1 && k + 1 < n && i + 1 < n && g[i + 1][j] != 1) {
        p++;
      } else {
        p = -1;
        break;
      }
    }
    ans.push_back(p);
  }
  return ans;
}

LL ms(LL q[], int l, int r) {
  if (l >= r)
    return 0;
  int mid = (l + r) >> 1;
  LL res = ms(q, l, mid) + ms(q, mid + 1, r);
  int i = l, j = mid + 1, k = l;
  while (i <= mid || j <= r) {
    if ((q[i] <= q[j] && i <= mid) || j > r)
      t[k++] = q[i++];
    else
      res += mid - i + 1, t[k++] = q[j++];
  }
  for (k = l; k <= r; k++)
    q[k] = t[k];
  return res;
}

int main() {
  vector<vector<int>> g= {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1},
      {1, 1, 1, 1, -1}, {
    -1, -1, -1, -1, -1
  }
};
  vector<int >res = findBall(g);

}
