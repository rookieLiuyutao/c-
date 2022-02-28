//
// Created by 刘宇韬 on 2022/2/25.
//

#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 105,M = 1005;

typedef pair<int,int> PII;
#define x first
#define y second
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int dis[N][N][M];
bool st[N][N][M];
//队列里需要多维护一个时间信息
struct Node{
  int a,b,t;
}p[N];
int n,m,T;


int  bfs(){
  queue<Node> q;
  memset(dis,0x3f,sizeof dis);
  dis[1][1][0] = 0;
  q.push({1,1,0});
  while (!q.empty()){
    auto t = q.front();
    q.pop();
    for(int i = 0; i <4; i++) {
      int a = t.a+dx[i],b = t.b+dy[i],tt = t.t+1;
      if (a<=0||a>n||b<=0||b>m||st[a][b][tt]) continue;
      if (dis[a][b][tt]>dis[t.a][t.b][t.t]+1){
        dis[a][b][tt]=dis[t.a][t.b][t.t]+1;
        q.push({a,b,tt});
      }
    }
  }
  int res = 0x3f3f3f3f;
  //在终点的所有时刻中找出最小的一个
  for(int i = 0; i <M; i++) {
    res = min(dis[n][m][i],res);
  }
  return res;
}

int main(){
  cin>>n>>m>>T;

  while (T--){
    int r,c,a,b;
    cin>>r>>c>>a>>b;
    //将所有障碍物存在的时间标记
    for(int i = a; i <=b; i++) {
      st[r][c][i] = true;
    }
  }

  cout<<bfs()<<endl;
}