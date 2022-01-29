
## 双指针(不离散化)
```
//
// Created by 95853 on 2022/1/24.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 105;
typedef long long LL;
typedef pair<int ,int>PII;

int a[N];
int n;
int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i];
  }
  sort(a,a+n);
  //记录答案
  int ans = 0;

  for(int i = 0; i <n; i++) {
    int res = 0;
    int l  = i,r = i;
    int range = 1;
    while(l - 1 >= 0) {
      // 找到最左边的本次能引爆的
      int ml = l - 1;
      while(a[l] - a[ml] <= range && ml >= 0) {
        ml--;
      }
      ml++;
      if(ml == l) break;
      l = ml;
      range++;
    }

    range = 1;
    // 找到能引爆的最右边草垛
    while(r + 1 < n) {
      int mr = r + 1;
      while (a[mr] - a[r] <= range && mr < n) {
        mr++;
      }
      mr--;
      if (mr == r)
        break;
      r = mr;
      range++;
    }

    res+=(r-l+1);
    ans = max(ans,res);
  }
  cout<<ans;
}

```
## BFS(离散化)
```
//
// Created by 95853 on 2022/1/24.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 110;
int a[N];
int n;
map<int ,int > s;
int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i];
    //初始化每一个点的爆炸范围为0；
    s.insert({a[i],0});
  }
  //记录答案
  int ans = 0;

  for(int i = 0; i <n; i++) {
    //宽搜开始前四步走：1.建立队列；2.清空st数组，3.起始点入队；4，在st数组中标记出始点
    queue<int>q;
    //这里的range数组相当于dist数组，即有st数组的作用，又记录[步长]，本题中步长即为[爆炸范围]
    auto range = s;
    q.push(a[i]);
    //初始点的爆炸范围为1
    range[a[i]] = 1;
    //存下以当前点为初始点算出的答案
    int res = 0;
    while (!q.empty()){
      auto t = q.front();
      q.pop();
      //每遍历到一个新点，说明就发生一次爆炸
      res++;
      for(int j = -range[t]; j <= range[t]; j++) {
        int next = t+j;
        if (range.count(next)&&range[next]==0){
          range[next]+= range[t]+1;
          q.push(next);
        }
      }

    }
    ans = max(res,ans);
  }
  cout<<ans;
}
```