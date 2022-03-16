//
// Created by 刘宇韬 on 2022/3/15.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1010;
string s,p;
unordered_map<char,int >mp;
int main(){
  cin>>s>>p;
  for(int i = 0; i <s.size(); i++) {
    mp[s[i]] = i;
  }
  cout<<s<<endl;
  cout<<p<<endl;
  int res = 1;
  for(int i = 0; i <p.size()-1; i++) {
    int j = i+1;
    if (mp[p[j]]<=mp[p[i]]){
      res++;
    }
  }
  cout<<res;
}