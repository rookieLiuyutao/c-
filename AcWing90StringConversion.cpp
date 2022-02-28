//
// Created by 刘宇韬 on 2022/2/27.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
int n = 0;
//存最多6种规则
string ta[6],tb[6];
//功能类似于dis，存每个点到终点的最小步数
unordered_map<string ,int>da,db;
queue<string>qa,qb;
void change(string &t){


}

int bfs(){
  while (!qa.empty()&&!qb.empty()){
    if (qa.size()<=qb.size()){
      auto t = qa.front();
      qa.pop();
      for(int i = 0; i < t.size(); i++) {
        for(int j = 0; j <n; j++) {
          if (t.substr(i,i+ta[j].size())==ta[j]){
            string state = t.substr(0,i)+ta[j]+ t.substr(i+ta[j].size());
            if (db.count(state))return da[t]+db[state]+1;
          }
        }
      }
    }
  }
}


int main(){
  string A,B;
  cin>>A>>B;
  string aa,bb;

  while (cin>>aa>>bb){
    ta[n] = aa;
    tb[n] = bb;
    n++;
  }
  int ans = bfs();
  ans<10?cout<<ans:cout<<"NO ANSWER!";
}    