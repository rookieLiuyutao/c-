#include "bits/stdc++.h"
using namespace std;
const int N = 1000005;

int main(){
  string x;
  cin>>x;
  stack<char> s;
  int res = 0;
  for(char & i : x) {
    if (i=='('){
      s.push(i);

    }else{
      if (!s.empty()){
        s.pop();
        res+=2;

      }
    }
  }
  cout<<res;
}