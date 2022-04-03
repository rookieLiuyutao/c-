//
// Created by 刘宇韬 on 2022/4/3.
//
/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
#define x first
#define y second
/**
 * https://www.acwing.com/problem/content/description/3631/
 * 要删掉一些边使，最多的点原本的最短路不变
 * 其实保留最短路上的点，删掉没有被扩展的点
 */
const int N = 200010,M = N;
int h[N], e[M], w[M], ne[M], idx;
LL dis[N];
bool st[N];
//存最短路树里的所有点
int p[N];
int n,m,k;
//当前已经增加了几个点
int cnt;
vector<int> res;
void add(int a, int b, int c)  // 添加一条边a->b，边权为c
{
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void djs(){
  priority_queue<PII,vector<PII>,greater<>> q;
  memset(dis,0x3f,sizeof dis);
  dis[1] = 0;
  q.push({0,1});
  while (!q.empty()){
    auto t = q.top();
    q.pop();
    if (st[t.y]) continue;
    if (p[t.y]!=-1&&cnt<k){
      res.push_back(p[t.y]);
      cnt++;
    }
    st[t.y] = true;
    for(int i = h[t.y]; ~i; i = ne[i]) {
      int j = e[i];
      if (dis[j]>dis[t.y]+w[i]){
        dis[j] = dis[t.y]+w[i];
        //i为边的编号
        //因为是无向图，且边的编号从0开始，点的编号从1开始，点编号 = 边编号/2+1
        p[j] = i/2+1;
        q.push({dis[j],j});
      }
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>m>>k;
  memset(h,-1,sizeof h);
  memset(p,-1,sizeof p);
  for(int i = 0; i <m; i++) {
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c), add(b,a,c);
  }

  djs();
  cout<<res.size()<<endl;
  for(auto i:res){
    cout<<i<<' ';
  }
}


