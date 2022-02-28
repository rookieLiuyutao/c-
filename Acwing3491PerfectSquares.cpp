//
// Created by 刘宇韬 on 2022/2/27.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
map<int ,int >s;
LL n;
int main(){
  cin>>n;
  for(int i = 2; i <n/i; i++) {
    if (n%i==0){
      int cnt = 0;
      while (n%i==0){
        n/=i;
        cnt++;
      }
      s.insert({i,cnt});
    }
    if (n>1)s.insert({n,1});
  }
  LL res = 1;
  for(auto x:s){
    cout<<x.first<<' '<<x.second;
    if (x.second&1)res*= x.first;
  }
  cout<< res;

}