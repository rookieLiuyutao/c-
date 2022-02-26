//
// Created by 刘宇韬 on 2022/2/23.
//
/*
 * https://www.luogu.com.cn/problem/P4011
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define x first
#define y second
const int N = 11,M = N*N,E = 400,P = 1<<10;
int h[M],e[E],ne[E],w[E],idx;
int dis[M][P];
int g[N][N],key[M];
bool st[M][P];
int n,m,p,k;
set<PII> s;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
void add(int a,int b,int c){
  e[idx] = b;
  w[idx] = c;
  ne[idx] = h[a];
  h[a] = idx++;
}
/**
 * 建剩下的边
 */
void build(){
  for(int i = 1; i <=n; i++) {
    for(int j = 1; j <=m; j++) {
      for(int u = 0; u <4; u++) {
        int a = i+dx[i],b = j+dy[i];
        if (a==0||a>n||b==0||b>m) continue;
        int v1  = g[i][j],v2 = g[a][b];
        if (!s.count({v1,v2})){
          add(v1,v2,0);
        }
      }
    }
  }
}

int bfs(){
  deque<PII> q;
  memset(dis,0x3f,sizeof dis);
  dis[1][0] = 0;
  q.push_back({1,0});
  while (!q.empty()){
    auto t = q.front();
    q.pop_front();
    if (st[t.x][t.y])continue;
    st[t.x][t.y] = true;
    //清况1：有钥匙
    if(key[t.x]){
        int state = t.y|key[t.x];
        if (dis[t.x][state]>dis[t.x][t.y]){
          dis[t.x][state]=dis[t.x][t.y];
          q.push_front({t.x,state});
        }
    }
    for(int i = h[t.x]; ~i ; i = ne[h[t.x]]) {
      int j = e[i];
      if ()
    }
  }
}

int main(){
    //地图有n行m列，钥匙有p类，共有k条边
    cin>>n>>m>>p>>k;
    //将所有点编号,从1开始编号
    int t = 1;
    for(int i = 1; i <=n; i++) {
      for(int j = 1; j <=m; j++) {
        g[i][j] = t;
      }
    }
    memset(h,-1,sizeof h);
    //读入所有边
    while (k--){
      //Xi1,Yi1,Xi2,Yi2,Gi：当 Gi≥1 时，表示 (Xi1,Yi1) 单元与 (Xi2,Yi2) 单元之间有一扇第 Gi 类的门，
      // 当 Gi=0 时，表示 (Xi1,Yi1) 单元与 (Xi2,Yi2) 单元之间有一面不可逾越的墙。
      int x1,y1,x2,y2,c;
      cin>>x1>>y1>>x2>>y2>>c;
      //通过坐标得到点的编号
      int a = g[x1][y1],b = g[x2][y2];
      //因为题中只告诉了墙，门，间的边，需要用一个set存下这些边，不在set中的就是普通空地
      s.insert({a,b});
      s.insert({b,a});
      //门有两条边
      if (c){
        add(a,b,c);
        add(b,a,c);
      }
    }
    int kc;
    cin>>kc;
    while (kc--){
      int a,b,c;
      cin>>a>>b>>c;
      key[g[a][b]] = c;
    }
    build();
    cout<<bfs();
}