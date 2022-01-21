#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
int a[N];
deque<int>w;
set<int > q;
int n,m;
int main(){
  cin>>n>>m;

  int res = 0;
  for(int i = 0; i <n; i++,) {
    cin>>a[i];
    if (q.count(a[i])){
      res = max(a[i],res);
    }
    if (i<m){
      w.push_back(a[i]);
      q.insert(a[i]);
    }else{
      q.erase(w.front());
      w.pop_front();
      w.push_back(a[i]);
      q.insert(a[i]);
    }
  }
  cout<<res;
}

