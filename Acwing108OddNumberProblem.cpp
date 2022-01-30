//
// Created by 95853 on 2022/1/29.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 505,M = N*N;
LL a[M],t[M],b[M];
LL ms(LL q[],int l,int r){
  if(l>=r)return 0;
  int mid = (l+r)>>1;
  LL res = ms(q,l,mid)+ms(q,mid+1,r);
  int i = l,j = mid+1,k = l;
  while(i<=mid||j<=r){
    if(q[i]<=q[j]&&i<=mid||j>r)t[k++] = q[i++];
    else res+=mid-i+1,t[k++] = q[j++];
  }
  for(k =l;k<=r;k++)q[k] = t[k];
  return res;
}

int main(){
  int n,x,span = 0;
  while (cin>>n){
    for(int i = 1 ; i <=n*n; i++) {
      cin>>x;
      if (x==0)span = 1;
      else a[i-span] = x;
    }
    span = 0;
    for(int i = 1; i <=n*n; i++) {
      cin>>x;
      if (x==0)span = 1;
      else b[i-span] = x;
    }
    LL res = ms(a,0,n*n-1);
    memset(t,0,sizeof t);
    LL ans = ms(b,0,n*n-1);
    if ((res&1)==(ans&1)){
      puts("TAK");
    }else{
      puts("NIE");
    }
  }
}    