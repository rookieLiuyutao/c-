//
// Created by 95853 on 2022/2/1.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1005;

typedef pair<double,double> PDD;

int n,d;
PDD a[N];

int main(){
  cin>>n>>d;
  int x,y;
  for(int i = 0; i <n; i++) {
    cin>>x>>y;
    if (d<y){
      cout<<-1;
      return 0;
    }
    double len = sqrt(d*d-y*y);
    a[i] = {x+len,x-len};
  }
  sort(a,a+n);
  int res = 0;
  double end = -2e9;
  for(int i = 0; i <n; i++) {
    if (a[i].second>end){
      res++;
      end = a[i].first;
    }
  }
  cout<<res;

}    