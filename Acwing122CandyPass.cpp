//
// Created by 95853 on 2022/1/30.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1000010;
int a[N],n;
LL s[N],c[N];
int main(){
  cin>>n;
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
    s[i] = s[i-1]+a[i];
  }
  LL avg = s[n]/n;
  LL res = 0;
  c[1] = 0;
  for(int i = 1; i <=n; i++) {
    c[i]+=s[i-1]-avg*(i-1);
  }
  sort(c+1,c+n+1);
  for(int i = 1; i <=n; i++) {
    res+= abs(c[i]-c[(n+1)/2]);
  }
  cout<<res;
}    