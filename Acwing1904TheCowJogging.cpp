#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
int n, a[N];
stack<int > q;
int main() {
  cin >> n;
  int x;
  for (int i = 0; i < n; i++)
    cin >> x >> a[i];
  reverse(a, a + n);
  int res = 1;

  q.push(a[0]);
  for (int i = 0; i < n; i++) {
    while (i<n-1&&q.top()>=a[i+1]){
      res++;
      break;
    }
  }
  for(int i = 0; i <q.size(); i++) {
    int t = q.top();
    q.pop();
    cout<<t<<' ';
  }
  //   for (int i = 0; i < n; i++)cout<< a[i]<<' ';

  cout << res << endl;
}
