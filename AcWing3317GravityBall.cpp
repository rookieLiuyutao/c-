//
// Created by 刘宇韬 on 2022/2/24.

#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 255,M = 400010;
typedef pair<int,int> PII;
#define x first
#define y second

int n,m,Q;
//要给所有障碍物编号
int id[N][N],cnt;
//存每个障碍物的坐标
PII ps[N*5];
//存每个格子走到每个方向，碰到的第一个障碍物
int tr[N][N][4];
int dis[N][N];
bool st[N][N];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

struct XQ{
  int a,b,c;
}q[M/4],e[M];

//邻接表
int h[N*5][N*5][4],ne[M],idx;


void bfs(){
  while (!q.empty()){
    auto t = q.front();
    q.pop();

    for(int i = 0; i <4; i++) {
      int a = t.x+dx[i],b = t.y+dy[i];
      if (a<0||a>=n||b<0||b>=n||st[a][b])continue;
      if (dis[a][b]>dis[t.x][t.y]+1){
        dis[a][b]=dis[t.x][t.y]+1;
      }
    }

  }
}

int main(){
  cin>>n>>m>>Q;
  memset(dis,0x3f,sizeof dis);
  while (m--){
    int a,b;
    cin>>a>>b;
    st[a][b] = true;
  }
  while (Q--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    q.push({a,b});
    q.push({c,d});
  }
  bfs();
  int res = 0x3f3f3f3f;
  for(auto p:tg) {
    res = min(res,dis[p.a][p.b]*p.c);
  }
  cout<<res;
}