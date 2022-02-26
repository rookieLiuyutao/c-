//
// Created by 刘宇韬 on 2022/2/24.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1010;
typedef pair<int,int> PII;
#define x first
#define y second
queue<PII> q;
int n,m,k,d;
int dis[N][N];
bool st[N][N];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

struct XQ{
  int a,b,c;
};
vector<XQ> tg;
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
  cin>>n>>m>>k>>d;
  memset(dis,0x3f,sizeof dis);
  while (m--){
    int a,b;
    cin>>a>>b;
    q.push({a,b});
    dis[a][b] = 0;
  }
  while (k--){
    int a,b,c;
    cin>>a>>b>>c;
    XQ  t = {a,b,c};
    tg.push_back(t);
  }
  while (d--){
    int a,b;
    cin>>a>>b;
    st[a][b] = true;
  }
  int res = 0x3f3f3f3f;
  for(auto p:tg) {
    res = min(res,dis[p.a][p.b]*p.c);
  }
  cout<<res;
}    