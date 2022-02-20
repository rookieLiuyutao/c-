#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 500010;
LL n, a[N], t[N];

LL ms(LL q[],int l,int r){
  if(l >= r)return 0;
  int mid=(l + r)>>1;
  LL res = ms(q, l, mid) + ms(q, mid + 1, r);
  int i= l,j=mid+1,k = l;
  while(i<=mid||j<= r){
    if((q[i]<=q[j]&&i<=mid)||j > r)t[k++]=q[i++];
    else res += mid - i + 1,t[k++]=q[j++];
  }
  for(k= l;k<= r;k++)q[k]=t[k];
  return res;
}


int main() {
//  while(cin>>n,n){
//    for (int i = 0; i < n; i++)cin >> a[i];
//    cout << ms(a, 0, n -1) << endl;
//  }



}
