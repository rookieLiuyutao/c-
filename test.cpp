#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N];
int n;
int main()
{
  cin>>n;
  int res = 0;
  for (int i = 0; i < n; i ++ )cin>>a[i];
  int j = 0;
  for (int i = 0; i < n; ){
    while(j<n&&a[j]<=a[i])j++;
    res+=(a[j]-a[i]);
    i = j;
  }
  cout << res;
}