/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010;
int n,a[N];
int main(){
  ios::sync_with_stdio(false);
  cin>>n;
  if (n<=2){
    puts("0");
    return 0;
  }
  for(int i = 0; i <n; i++) {
    cin>>a[i];
  }
  int res = 0;
  for(int i = 1; i <n-1; i++) {
    int j = i-1,k = i+1;
    if (a[j]<a[i]&&a[k]<a[i]||a[j]>a[i]&&a[k]>a[i]){
      res++;
    }
  }
  cout<<res;
}