//
// Created by 刘宇韬 on 2022/4/6.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
string a,b;
string res;

vector<string>s;

int main(){
  cin>>a>>b;
  sort(a.begin(), a.end());
  if (a.size()<b.size()){

    reverse(a.begin(), a.end());
    cout<<a;
  }else{
    for(int i = 0; i <a.size(); i++) {
      for(int j = i+1; j <a.size(); j++) {
        string temp = a;
        swap(temp[i],temp[j]);
        if (temp>a&&temp<=b){
          a = temp;
        }
      }
    }
    cout<<a;
  }


}