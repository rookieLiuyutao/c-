//
// Created by 刘宇韬 on 2022/2/4.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 110;
typedef pair<int,int> PII;
#define x first
#define y second
int n;
PII a[N];
int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i].x>>a[i].y;
  }
  sort(a,a+n);
  int res = 0;
  for(int i = 0; i <n; i++) {
    int l = 0 ,r = 0;
    int sum = 0;
    for(int j = 0; j <n; j++) {
      if (j==i)continue;
      if (a[j].x<=r){
        sum+= a[j].y-r;
      } else{
        sum+=a[j].y-a[j].x;
      }
      r = max(r,a[j].y);
      res = max(res,sum);
    }
  }
  cout<<res;
}