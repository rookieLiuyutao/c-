//
// Created by 95853 on 2022/2/1.
//
#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9 + 7;
typedef long long LL;
typedef pair<int,int> PII;
#define r first
#define l second
map<int ,int>s;
vector<PII> a;
int n,m;
int main(){
  cin>>n>>m;
  for(int i = 0; i <n; i++) {
    int p,c;
    cin>>p>>c;
    s[p]+=c;
  }
  int sum = 0;
  for(auto p:s){
    a.push_back({p.r, sum});
    sum+=p.l;
  }
  a.push_back({1e9+7,sum});
  for(int i = 0; i <m; i++) {
    int l,r;
    cin>>l>>r;
    auto p1 = upper_bound(a.begin(), a.end(),(PII){l,-INF});
    auto p2 = upper_bound(a.begin(), a.end(),(PII){r,INF});
    cout<<p2->l -p1->l <<endl;
  }
}    