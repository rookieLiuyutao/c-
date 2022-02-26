//
// Created by 刘宇韬 on 2022/2/25.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 205,M = N*N;
typedef pair<int,int> PII;
#define x first
#define y second
int h[N],e[M],ne[M],idx;
int dis[N][N];
void add(int a,int b){
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}
PII p[N];
int n,m,k,r;

bool check(PII a, PII b)
{

  LL dx = a.x - b.x;
  LL dy = a.y - b.y;
  return dx * dx + dy * dy <= (LL)r * r;
}
int  bfs(){
  queue<PII> q;
  memset(dis,0x3f,sizeof dis);
  dis[1][0] = 0;
  //队列里放的是{点编号，截止目前用的路由器的数量}
  q.push({1,0});
  while (!q.empty()){
    auto t = q.front();
    q.pop();
    for(int i = h[t.x]; ~i; i = ne[i]) {
      int j = e[i],cnt = t.y;
      
      if (j>n)cnt++;
      if (cnt<=k){
        if (dis[j][cnt]>dis[t.x][t.y]+1){
          dis[j][cnt] = dis[t.x][t.y]+1;
          q.push({j,cnt});
        }
      }
    }
  }
  int res = 1e8;
  for(int i = 0; i <=k; i++) {
    res = min(res,dis[2][i]);
  }
  return res-1;
}

int main(){
  cin>>n>>m>>k>>r;
  memset(h,-1,sizeof h);
  for(int i = 1; i <=n+m; i++) {
    cin>>p[i].x>>p[i].y;
  }
  for(int i = 1; i <=n+m; i++) {
    for(int j = i+1; j <=n+m; j++) {
      if (check(p[i],p[j])){
        add(i,j);
        add(j,i);
      }
    }
  }
  cout<<bfs()<<endl;
}