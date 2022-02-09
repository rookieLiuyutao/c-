//
// Created by 刘宇韬 on 2022/2/1.
//
#include<bits/stdc++.h>
using namespace std;
//存每个字母出现的两个位置
vector<int> p[26];
int main(){
  string s;
  cin>>s;
  int n = s.size();
  for(int i = 0;i<n;i++){
    p[s[i]-'A'].push_back(i);
  }
  int res = 0;
  //枚举每一对字母
  for(int i = 0;i<26;i++){
    for(int j = i+1;j<26;j++){
      int cnt = 0;
      //枚举这对字母的两个位置
      for(auto x:p[j]){

        if(x>p[i][0]&&x<p[i][1]){
          cnt++;
        }
      }
      //只有两个字母中的一个在另一对之间，才是嵌套
      if(cnt==1)res++;
    }
  }
  cout << res;
}