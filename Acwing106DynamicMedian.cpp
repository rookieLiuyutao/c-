//
// Created by 95853 on 2022/1/29.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;

int main(){
  int T;
  cin>>T;

  while (T--){
    int m,n;
    priority_queue<int>down;
    priority_queue<int,vector<int>,greater<>>up;
    cin>>m>>n;
    int cnt=0;
    for(int i = 0; i <n; i++) {
      int x;
      cin>>x;
      if (down.empty()||x>=down.top())
        down.push(x);
      else up.push(x);
      if (up.size()>down.size()+1){
        down.push(up.top());
        up.pop();
      }else {
        up.push(down.top());
        down.pop();
      }
      if (i%2){
        cout<<down.top()<<' ';
        if (++cnt%10==0)
          puts("");
      }
    }
    if (cnt%10)
      puts("");
  }
}