#include "bits/stdc++.h"
using namespace std;
const int N = 105;
typedef long long LL;
LL a[N];
//用map可以优化查找过程，并且标记这个数有没有被选过
unordered_map<LL,bool> q;

int n;

int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i];
    q.insert({a[i], true});
  }

  for(int i = 0; i <n; i++) {
    //枚举每个数作为首位
    LL first = a[i];
    //存下每一次的答案
    vector<LL> ans;
    //初始化，清空所有标记
    for(auto &x: q){
      x.second = false;
    }
    //将第一个数加进去
    ans.push_back(first);
    //只要有存在合条件，且没有用过的数，就一直往后加。注意一定要加上first %3==0否则就不是整除
    while ((q.count(first *2)&&!q[first *2])||(first %3==0&& q.count(first /3)&&!q[first /3])){
      if (q.count(first *2)&&!q[first *2]){
        ans.push_back(first *2);
        //标记这个数为用过
        q[first *2] = true;
        first = first *2;
      }else if (first %3==0&& q.count(first /3)&&!q[first /3]){
        ans.push_back(first /3);
        q[first /3] = true;
        first = first /3;
      }

    }
    //如果所有数都加进去了，说明找到了答案
    if (ans.size()==n){
      for(int j = 0; j <n; j++) {
        cout<<ans[j]<<' ';
      }
      break;
    }
  }
}