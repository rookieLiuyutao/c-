//
// Created by 95853 on 2022/2/1.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1005;
int n;
typedef pair<int,int> PII;
#define y first
#define x second
PII a[N];
int main(){
  cin>>n;
  int x0,y0;
  cin>>x0>>y0;
  for(int i = 0; i <n; i++) {
    cin>>a[i].x>>a[i].y;
  }
  sort(a,a+n);
  for(int i = 0; i <n; i++) {
    cout<<a[i].x<<' ' <<a[i].y<<endl;
  }
  LL left = x0;
  LL res = 0;
  for(int i = 0; i <n; i++) {
    res=max(left/a[i].y,res);
    left*=a[i].x;
  }
  cout<<res;

}    