#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n, ret = 0; cin >> n;
  vector<int> a(n); for (int & x : a) cin >> x;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i ++ )
    for (int j = i + 1; j < n; j ++ )
      ret += upper_bound(a.begin(), a.end(), 3 * a[j] - 2 * a[i]) - lower_bound(a.begin(), a.end(), 2 * a[j] - a[i]);
  cout << ret << endl;
  return 0;
}

