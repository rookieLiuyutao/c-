//
// Created by 刘宇韬 on 2022/4/7.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
/**
 * https://www.acwing.com/problem/content/1249/
 * 后缀表达式可以调整运算顺序，相当于中缀运算都带上括号
 * 最终可以只有一次减法，剩下全是加法
 * 这一次减法就选取最大数-最小数
 */

const int N = 100010;
int n,m;
vector<int> a;
int main(){
  cin>>n>>m;
  for(int i = 0; i <n+m+1; i++) {
    int x;
    cin>>x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  int k = n+m+1;
  LL res = 0;
  if (m ==0){
    //如果没有减法
    for(int i = 0; i <k; i++) {
      res+=a[i];
    }
  }else{
    res=a[k-1]-a[0];
    for(int i = 1; i <k-1; i++) {
      res+= abs(a[i]);
      //   cout << a[i]<<' ';
    }
  }
  cout<<res;

}