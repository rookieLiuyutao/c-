//
// Created by 刘宇韬 on 2022/3/31.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 2e5+5;
string s;
int n;
int main(){
  int T;
  cin>>T;
  while (T--){
    cin>>n>>s;
    int res = 0;
    vector<int> st;
    for(int i = 0; i <s.size(); i++) {
      if (s[i]=='0') st.push_back(i);
    }
    for(int i = 1; i <st.size(); i++) {
      if (st[i]-st[i-1]<=2){
        res+=2-(st[i]-st[i-1])+1;
      }
    }
    cout<<res<<endl;
  }
}    