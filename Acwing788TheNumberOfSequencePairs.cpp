#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
int n, a[N], tmp[N];

LL ms(int q[], int l, int r) {
  if (l >= r)
    return 0;
  int mid = (l + r) >> 1;
  LL res = ms(q, l, mid) + ms(q, mid + 1, r);
  int k = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) {
      tmp[k++] = q[i++];

    } else {
      res += mid - i + 1;
      tmp[k++] = q[j++];
    }
  }
  while (i <= mid)
    tmp[k++] = q[i++];
  while (j <= r)
    tmp[k++] = q[j++];
  for (i = l, j = 0; i <= r; i++, j++) {
    q[i] = tmp[j];
  }
  return res;
}

LL ms2(int q[], int l, int r) {
  if (l >= r)
    return 0;
  int mid = (l + r) / 2;
  LL res = ms2(q, l, mid) + ms2(q, mid + 1, r);
  int i = l, j = mid + 1, k = l;
  while (i <= mid || j <= r) {
    if ((q[i] <= q[j] && i <= mid) || j > r) {
      tmp[k++] = q[i++];
    } else {
      res += mid - i + 1;
      tmp[k++] = q[j++];
    }
  }
  for (k = l; k <= r; k++) {
    q[k] = tmp[k];
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << ms(a, 0, n - 1) << endl;
}
