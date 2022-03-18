#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 105,M = N*4;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;  // 时间戳
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;  // 每个点所属分量编号
int din[N],dout[N];
void add(int a, int b)  // 添加一条边a->b
{
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}


void tarjan(int u)
{
  dfn[u] = low[u] = ++ timestamp;
  stk[ ++ top] = u, in_stk[u] = true;

  for (int i = h[u]; ~i; i = ne[i])
  {
    int j = e[i];
    if (!dfn[j])
    {
      tarjan(j);
      low[u] = min(low[u], low[j]);
    }
    else if (in_stk[j])
      low[u] = min(low[u], dfn[j]);
  }

  if (dfn[u] == low[u])
  {
    ++ scc_cnt;
    int y;
    do {
      y = stk[top -- ];
      in_stk[y] = false;
      id[y] = scc_cnt;
    } while (y != u);
  }
}

int main(){
  int n;
  cin>>n;
  memset(h,-1,sizeof h);
  for(int i = 1; i <=n; i++) {
    int b;
    while (cin>>b,b){
      add(i,b);
    }
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
      //如果点i和点k不在1个强联通分量中
      if (a!=b){
        dout[a]++;
        din[b]++;
      }
    }
  }
  //统计起点和终点的数量
  int a = 0,b = 0;
  for(int i = 1; i <=scc_cnt; i++) {
    if (!din[i]) a++;
    if (!dout[i])b++;
  }
  //问题一即为起点的数量
  cout<<a<<endl;

  if (scc_cnt==1)
    puts("0");
  else{
    cout<<max(a,b)<<endl;
  }


}
