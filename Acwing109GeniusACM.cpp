//
// Created by 95853 on 2022/1/30.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 500010;
LL n,m,t,ans,cnt;
LL a[N],b[N],tmp[N],p[N];
void mer(int mid ,int l,int r){
  int i = l,j = mid+1,k = l;
  while (i<=mid||j<=r){
    if (a[i]<a[j]&&i<=mid||j>r)tmp[k++] = a[i++];
    else tmp[k++] = a[j++];
  }
}
bool check(int mid ,int l, int r){
  for(int i = mid; i <=r; i++) {
    a[i] = p[i];
  }
  sort(a+mid,a+r+1);
  mer(l,mid,r);
  LL sum = 0;
  for(int i = 1; i <=(r-l+1)>>1&&i<=m; i++) {
    sum+=(tmp[r-i+1]-tmp[l+i-1])*(tmp[r-i+1]-tmp[l+i-1]);
  }
  if (sum<=cnt){
    for(int i = l; i <=r; i++) {
      a[i] = tmp[i];
    }
    return true;
  }else{
    return false;
  }
}
int main(){

}