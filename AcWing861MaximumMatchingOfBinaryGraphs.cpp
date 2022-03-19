
/**
 * @author 刘宇韬 on 2022/3/19.
* https://www.luogu.com.cn/problem/P3386
*/
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 505,M = 100010;
//由于点数只有500，可以使用邻接矩阵来存图，必须搭配st数组，防止重复搜索
bool g[N][N],st[N];
int match[N];
int m,n,k;

bool dfs(int u){
  //枚举男生所有看上的女生
  for(int i = 1; i <=m; i++) {
    //如果之前没有考虑过，因为是邻接矩阵，所以u->i有边才是看上
    //注意，一定要先判g[u][i]，后判!st[i]
    if (g[u][i]&&!st[i]){
      st[i] = true;
      //如果这个女生还没有匹配男生，或者她喜欢的那个男生还有备胎(可以把这个妹子让给你)
      if (match[i]==0|| dfs(match[i])){
        match[i] = u;
        return true;
      }
    }
  }
  return false;
}

int main(){
  cin>>n>>m>>k;
  //读入图
  for(int i = 0; i <k; i++) {
    int a,b;
    cin>>a>>b;
    g[a][b] = true;
  }
  //遍历二分图左右部的任意一边，给那一边的点寻找匹配
  //遍历所有的男生或女生，给他(她)们分配对象
  //这里以男生为例
  int res = 0;
  for(int i = 1; i <=n; i++) {
    //重新考虑所有女生，保证每个女生只考虑一遍
    memset(st,0,sizeof st);
    //如果当前男生找到了对象，匹配数+1
    if (dfs(i))res++;
  }
  cout<<res;
}    