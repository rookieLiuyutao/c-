//
// Created by 刘宇韬 on 2022/3/10.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 10010,M = 50010;

int n,m;
//邻接表
int h[N],e[M],ne[M],idx;
//记录每个点在深搜时的时间戳
int dfn[N];
//存强联通分量的根，即每个强联通分量中时间戳最小的节点
int low[N];
//时间戳
int ts;
//用来放点的栈
int stk[N],top;
//标记点是否在栈中的标记数组
bool st[N];
//强联通分量的编号，记录每个点属于哪个强联通分量
int id[N];
//当前强联通分量的个数(编号)
int scc_cnt;
//每个强联通分量中点的个数
int cnt[N];
//每个点的出度
int dout[N];

void add(int a,int b){
  e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void tarjan(int u){
  //求当前点的时间戳
  dfn[u] = low[u] = ++ts;
  //把点入栈
  stk[++top] = u;
  st[u] = true;
  //遍历所有邻边，更新最小时间戳
  for(int i = h[u]; i !=-1; i = ne[i]) {
    int j = e[i];
    if (!dfn[j]){
       tarjan(j);
       //更新最小时间戳
       low[u] = min(low[u ],low[j]);

    }else if (st[j]){
      low[u] = min(low[u],dfn[j]);
    }
  }
  //如果当前的点就是最小的，说明它是强联通分量子树的根
  if (dfn[u] == low[u]){
    //找出所有该强联通分量中的点
    ++scc_cnt;
    int y;
    do{
      y = stk[top--];
      st[stk[y]] = false;
      id[y] = scc_cnt;
      cnt[scc_cnt]++;
    } while (y!=u);
  }
}

int main(){
  cin>>n>>m;
  memset(h,-1,sizeof h);
  while (m--){
    int a,b;
    cin>>a>>b;
    add(a,b);
  }
  for(int i = 1; i <=n; i++) {
    if (!dfn[i]){
      tarjan(i);
    }
  }

  for(int i = 1; i <=n; i++) {
    for(int j = h[i]; j !=-1; j = ne[j]) {
      int k = e[j];
      int a = id[i],b = id[k];
      if (a!=b){
        dout[a]++;
      }
    }
  }
  //求所有强联通分量中，出度为0的点的数量和
  int no_out = 0,res = 0;

  //枚举每个分量
  for(int i = 1; i <=scc_cnt; i++) {
    if (dout[i]==0){
      no_out++;
      res+=cnt[i];
      if (no_out > 1)//如果有k>1个出度为0的 则会存在k-1头牛不被所有牛欢迎
      {
        res = 0;
        break;
      }
    }
  }
  cout<<res;

}