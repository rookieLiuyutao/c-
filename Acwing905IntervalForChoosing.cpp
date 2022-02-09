//
// Created by 95853 on 2022/2/1.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
typedef pair<int,int> PII;
#define r first
#define l second
PII a[N];
int n;
int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i].l>>a[i].r;
  }
  sort(a,a+n);

  int res = 0,end = -2e9;
  for(int i = 0; i <n; i++) {
    if(a[i].l>end){
      res++;
      end = a[i].r;
    }
  }
  cout<<res;
}