//
// Created by 95853 on 2022/1/25.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
int n;

int main(){
  cin>>n;
  unordered_map<char,int> map[2];
  for(int i = 0; i <n; i++) {
    char c;
    int v;
    cin>>c>>v;
    map[v%2][c]++;
  }
  unordered_map<char,int> v;
  string s = "BESIGOM";
  int res = 0;
  for(int i = 0; i <1<<7; i++) {
    for(int j = 0; j <7; j++) {
      v[s[j]] = i>>j&1;
    }
    if ((v['B'] + v['I']) * (v['G'] + v['O'] + v['E'] + v['S']) * v['M'] % 2 == 0){
      int sum = 1;
      for(int j = 0; j <7; j++) {
        sum*=map[i>>j&1][s[j]];
      }
      res+=sum;
    }
  }
  cout<<res;

}