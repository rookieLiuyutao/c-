//
// Created by 刘宇韬 on 2022/4/6.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
/**
 * 本题是要求所有区间和中，有几个小于给定值，即s[r]-s[l-1]<t
 * 如果用前缀和+枚举左右端点，会超时
 * 如何优化左右端点的的枚举？
 * 将问题转化为：在所有s[r]-t的前缀中，有多少满足 s[l-1]>s[r]-t
 */

const int N = 400005;
LL tr[N];
LL a[N];
vector<LL> s;
int n;
LL m;
void add(int x,int v){
  for(int i = x; i <N; i+=i&-i) {
    tr[i]+=v;
  }
}
LL query(int x){
  LL res = 0;
  for(int i = x; i ; i-=i&-i) {
    res+=tr[i];
  }
  return res;
}

int get(LL x){
  return lower_bound(s.begin(), s.end(),x)-s.begin()+1;
}

int main(){
  ios::sync_with_stdio(false);
  cin>>n>>m;
  s.push_back(0);  // 0 需要用到
  s.push_back(-m);
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
    a[i]+=a[i-1];
    s.push_back(a[i]);
    s.push_back(a[i]-m);
  }
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),s.end());

  LL res = 0;
  add(get(a[0]),1);
  for(int i = 1; i <=n; i++) {
    res+= query(get(a[i]-m));
    add(get(a[i]),1);
  }
  cout<<res;
}    
