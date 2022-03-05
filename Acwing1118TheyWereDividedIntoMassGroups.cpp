//
// Created by 刘宇韬 on 2022/3/5.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
vector<unordered_set<int>> t (10);
int n;
int a[11];
bool st[11];
void get_ys(int idx,int x){
  for(int i = 2; i <=x/i; i++) {
    if (x%i==0){
      t[idx].insert(i);
      while (x%i==0){
        x/=i;
      }
    }
  }
  if (x!=1)t[idx].insert(x);
}

int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i];
    get_ys(i,a[i]);
  }
  int res = 0;
  for(int i = 0; i <n; i++) {
    if (st[i])continue;
    st[i] = true;
    bool flag;
    for(int j = 0; j <n; j++) {
      if (i==j||st[j]) continue;
       flag = true;
      for(auto x:t[j]) {
        if (t[j].count(x)) {
          flag = false;
          break;
        }
      }
      if (flag) {
        st[j] = true;

      }else{
        res++;
      }
    }
    cout <<res;
  }
}