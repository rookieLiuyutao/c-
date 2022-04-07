//
// Created by 刘宇韬 on 2022/4/6.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1010;
typedef pair<string ,string> PSS;
#define x first
#define y second
PSS p[N];
map<string,string> s;
set<string > head;
int n;
int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>p[i].x>>p[i].y;
  }


  string tail;
  for(int i = 0; i <n; i++) {
    if (!head.empty()){
      for(auto j:head){
        if (s.count(s[j])){
          while (s.count(s[j])){
            s[j] = s[s[j]];
          }
        }else{
          if (!head.count(p[i].x)){
            head.insert(p[i].x);
          }
          s.insert(p[i]);
        }
      }
    }else{
      s.insert(p[i]);
      head.insert(p[i].x);
    }


  }
  cout<<s.size()<<endl;
  for(auto t: s){
    cout<<t.x<<' '<<t.y<<endl;
  }
}    