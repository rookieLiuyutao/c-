#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
deque<int > q;
const int N = 100010;
int n,m;
PII a[N];
int q[N], range[N];
int main()
{
  cin >> n>>m;
  for (int i = 1; i <= n; i ++ )cin>>a[i].y>>a[i].x;
  sort(a+1,a+n+1);
  for(int i = 1; i <=n; i++) {
    q[i]+= q[i-1]+a[i].y;
    range[i] = a[i].x;
  }
  int res = 0,begin = 0;
  for(int i = 1; i <=n; i++) {
    int l = upper_bound(range +1, range +n+1, range[i]+2*m)-(range +1);
    if (q[l]- q[i]>res){
      res = q[l]- q[i];
      begin = i;
    }
  }
  cout<<begin<<' ' <<res;
}