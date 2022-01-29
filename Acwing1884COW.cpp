//
// Created by 95853 on 2022/1/21.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
LL dp[N];
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cc = 0,co = 0,x = 0;
    LL res = 0;
    for(int i = 0; i <s.size(); i++) {
      if (s[i]=='C')cc++;
      else if (s[i]=='O'&&cc>0)co++;
      else{
        if (dp[x]==0)dp[i]+=cc*co;
        else{
          dp[i] = dp[x]+dp[x]*co;
          x = i;
          cc = co =0;
        }
      }
    }
    for(int i = 0; i <n; i++) {
      res = max(dp[i],res);
    }
    cout<<res;
}