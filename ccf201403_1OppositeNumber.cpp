//
// Created by 95853 on 2021/8/12.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n,x,a[N];
int main(){
    cin>>n;
    for(int i = 0; i <n; i++) {
      cin>>a[i];
    }
    int res = 0;
    for(int i = 0; i <n; i++) {
      for(int j = 0; j <i; j++) {
          if (a[j] == -a[i])res++;
      }
    }
    cout<<res;
}
