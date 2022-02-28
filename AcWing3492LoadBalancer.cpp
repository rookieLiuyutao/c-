//
// Created by 刘宇韬 on 2022/2/27.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 200010;

struct Node{
  int id,end,w;
  bool operator <(const Node& x){
    return end<x.end;
  }
};
int v[N];
priority_queue<Node,vector<Node>,greater<Node>>q;
int n,m;
int main(){
  cin>>n>>m;
  for(int i = 0; i <n; i++) {
    cin>>v[i];
  }
  while (m--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while (!q.empty()&&q.top().end<a){
      auto t = q.top();
      q.pop();
      v[t.id]+=t.w;
    }
    if (v[b]>=d){
      v[b]-=d;
      q.push({b,a+c,d});
      cout<<v[b]<<endl;
    }else{
      cout<<-1<<endl;
    }
  }
}    