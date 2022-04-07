//
// Created by 刘宇韬 on 2022/4/6.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 3010;
int a[N];
int n;
unordered_map<int,int>mp;
int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i];
    mp[a[i]]++;
  }
  sort(a,a+n);
  int res = 0;
  for(int i = 0; i <n; i++){
    if (mp.count(a[i])&&mp[a[i]]>1){
      int p = a[i];
      mp[a[i]]--;
      while (mp.count(p)){
        res++;
        p++;
      }
      mp[p]++;
    }
  }
  cout<<res;
}