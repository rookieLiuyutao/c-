/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define pb push_back
#define fi first
#define se second
const int N = 500005, M = 1000005;
int n,k;
int a[N],cnt[M];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>k;
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
  }
  int t = 0;
  for(int i = 1,j = 1; i <=n; i++) {
    if (cnt[a[i]]==0) t++;
    cnt[a[i]]++;
    while (t>k){

      cnt[a[i]]++;
    }
  }

}