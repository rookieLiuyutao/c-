//
// Created by 刘宇韬 on 2022/3/17.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 5005,M = 20005;
int n,m;

int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;  // 时间戳
int stk[N], top;
int id[N], dcc_cnt;  // 每个点所属分量编号
bool is_bridge[M];
//记录每个点的度
int d[N];
void add(int a,int b){
  e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void tarjan(int u, int from)
{
  //给当前遍历的点打上时间戳
  dfn[u] = low[u] = ++timestamp;
  //将当前点入栈
  stk[++top] = u;
  //遍历该点的所有邻边，i表示边
  for(int i = h[u]; i !=-1; i = ne[i]) {
    //j为u点的i边指向的点
    int j = e[i];
    //如果没有时间戳，说明还没遍历到
    if (!dfn[j]){
      //往下搜
      tarjan(j,i);
      //回溯回来的时候带着子节点的信息，更新从u开始走所能遍历到的最小时间戳
      low[u] = min(low[u],low[j]);
      // 如果dfn[u] < low[j] j无论如何往上走不到u 且j能到的最高的点low[j] = dfn[j]
      if (dfn[u]<low[j]){
        //说明边i，和i的反向边都是桥
        is_bridge[i] = is_bridge[i^1] = true;
      }
      // j遍历过 且i不是反向边(即i不是指向u的父节点的边),因为我们不能用u的父节点的时间戳更新u
    } else if (i!=(from^1)){
      low[u] = min(low[u],dfn[j]);
    }
  }
  //如果当前的点就是最小的，说明它是强联通分量子树的根
  if (dfn[u]==low[u]){
    ++dcc_cnt;
    int y;
    do{
      y = stk[top--];
      //存下栈顶的点在哪个强联通分量中
      id[y] = dcc_cnt;
    } while (y!=u);
  }
}

int main(){
  cin>>n>>m;
  memset(h,-1,sizeof h);
  while (m--){
    int a,b;
    cin>>a>>b;
    add(a,b ), add(b,a);
  }

  tarjan(1,-1);

  //遍历所有边
  for(int i = 0; i <idx; i++) {
    //如果边i是桥 在其所连的出边的点j所在强连通分量的度+1,桥两边的双连通分量各+1
    if (is_bridge[i]){
      //d[]记录点的度，id记录点在哪个双联通分量中
      d[id[e[i]]]++;
    }
  }
  int res = 0;
  //遍历每个双联通分量
  for(int i = 1; i <=dcc_cnt; i++) {
    if (d[i]==1){
      res++;
    }
  }
  cout<<(res+1)/2;

}
