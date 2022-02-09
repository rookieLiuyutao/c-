//
// Created by 95853 on 2022/1/30.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 50010;
struct cow{
  //开始和结束吃草的时间
  int x,y;
  //这头牛所在的组号
  int id;
  bool operator < (const cow& a)const{
    if (y == a.y){
      return x>a.x;
    }
    return y>a.y;
  }
}a[N];
vector<cow>res;
bool cmp(cow a,cow b)
{
  if (a.x==b.x)
    return a.y<b.y;
  return a.x<b.x;
}
bool cmp2(cow a,cow b)
{
  if (a.id==b.id){
    if (a.x==b.x){
      return a.y<b.y;
    }
  }
  return a.id<b.id;
}
int n;
int ans[N];
int main(){
  cin>>n;
  for(int i = 1; i <=n; i++) {
    cin>>a[i].x>>a[i].y;
    a[i].id = i;
  }
  sort(a+1,a+n+1, cmp);
  //heap存每一组最后一头牛
  priority_queue<cow,vector<cow>> heap;
  for(int i = 1; i <=n; i++) {
    if (!heap.empty()&&heap.top().y<a[i].x){
      ans[a[i].id] = ans[heap.top().id];
      res.push_back({a[i].x,a[i].y,a[i].id});
      heap.pop();
    }else{
      ans[a[i].id] = heap.size()+1;
      res.push_back({a[i].x,a[i].y,a[i].id});

    }
    heap.push(a[i]);
  }
  cout<<heap.size()<<endl;
  for(int i = 1; i <=n; i++) {
    cout<<ans[i]<<endl;
  }
  for(int i = 0; i <n; i++) {
    cout<< heap.top().x<<' '<<heap.top().y<<' '<<heap.top().id<<endl;
    heap.pop();
  }
  sort(res.begin(), res.end(), cmp2);
  int tmp = res[0].id;
  cout<<tmp<<' ';
  for(int i = 1; i <res.size(); i++) {
    if (res[i].id!=tmp){
      cout<<endl;
      cout<<res[i].id<<' ';
      tmp = res[i].id;
    } else{
      cout<<res[i].id<<' ';
    }
  }
}    