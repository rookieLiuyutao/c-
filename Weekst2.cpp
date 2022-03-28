/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 205;
#define pb push_back
#define fi first
#define se second
int n,k;
int a[N],b[N];
bool check(int x){
  memset(b,0,sizeof b);
  for(int i = 1; i <=n; i++) {
    int l  = a[i]-x-1,r = a[i]+x-1;
    l = max(1,l);
    r = min(n,r);
    b[l]++;
    b[r+1]--;
  }
  bool flag = true;
  for(int i = 1; i <=n; i++) {
    b[i]+=b[i-1];
    if (b[i]==0) {
      flag = false;
      break;
    }
  }
  return flag;
}
int main(){
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  while (T--){
    memset(a,0,sizeof a);

    cin>>n>>k;
    for(int i = 1; i <=n; i++) {
      cin>>a[i];
      a[i]++;
    }
    int l = 0,r = n;
    while (l<r){
      int mid = (l+r)>>1;
      if (check(mid)){
        r = mid;
      }else{
        l = mid+1;
      }
    }
    cout<<l<<endl;
  }
}
