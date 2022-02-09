//
// Created by 95853 on 2022/1/31.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
typedef pair<int,int> PII;
#define r first
#define l second
PII a[N];
int main(){
  int n;
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i].r >>a[i].l;
  }
  sort(a,a+n);
  int res = 1;
  int minr = a[0].l;
  for(int i = 1; i <n; i++) {
    if (a[i].r <=minr) {
      minr = min(minr,a[i].l);
    } else{
      res++;
      minr = a[i].l;
    }
  }
  cout<<res;
}    
