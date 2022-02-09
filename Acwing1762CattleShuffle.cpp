//
// Created by 刘宇韬 on 2022/2/3.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 110;
int a[N],id[N];
int main(){
  int n;
  cin>>n;
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
  }
  for(int i = 1; i <=n; i++) {
    cin>>id[i];
  }
  for(int i = 0; i <3; i++) {
    int p[N];
    for(int j = 1; j <=n; j++) {
      p[i]  = a[a[i]];
    }
    memcpy(id, p, sizeof id);

  }
  for(int j = 1; j <= n; j++) {
    cout<<id[j]<<' ';
  }
}