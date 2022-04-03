//
// Created by 刘宇韬 on 2022/4/3.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
int a[N],n,k;
int main(){
  int T;
  cin>>T;
  while (T--){
    cin>>n>>k;
    for(int i = 0; i <n; i++) {
      cin>>a[i];
    }
    int res = 0x3f3f3f3f;
    for(int i = 1; i <=100; i++) {
      int cnt = 0;
      for(int j = 0; j <n;) {
        if (a[j]!=i){
          cnt++;
          j+=k;
        }else{
          j++;
        }
      }
      res = min(res,cnt);
    }
    cout<<res<<endl;
  }
}    