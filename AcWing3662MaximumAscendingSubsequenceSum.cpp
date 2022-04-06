//
// Created by 刘宇韬 on 2022/4/6.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
LL tr[N];
vector<int> s;
LL dp[N];
int a[N];
int n;
void add(int x, LL v) {
  for (int i = x; i <= n; i += i & -i) {
    tr[i] = max(tr[i], v);
  }
}

LL query(int x) {
  LL res = 0;
  for (int i = x; i <= n; i++) {
    res = max(res, tr[i]);
  }
  return res;
}
int get(int x){
  return lower_bound(s.begin(), s.end(),x)-s.begin()+1;
}
int main() {
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i];
    s.push_back(a[i]);
  }
  //离散化:先排序，再去重，这样原数组的值就被紧凑的映射在s的下标上
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()),s.end());

  LL res = 0;
  for(int i = 0; i <n; i++) {
    int k = get(a[i]);
    dp[i] = query(k-1)+a[i];
    res = max(dp[i],res);
    add(k,dp[i]);
  }
  cout<<res;
}