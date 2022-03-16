//
// Created by 刘宇韬 on 2022/3/15.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 40010,M = N*2;
typedef long long LL;
int h[N],w[M],ne[M],e[M],idx;

//depth记录当前点的深度，默认根节点深度为1
//fa表示，往上跳2^k步后的父亲节点
int q[N],depth[N],fa[N][16];
bool st[N];
int n,m;
/**
 *  树的普通宽度优先遍历
 *  用倍增预处理除每个节点，向上走的祖先是谁
 * @param root
 */
void bfs(int root){
  memset(depth,0x3f,sizeof depth);
  depth[0] = 0;
  depth[root] = 1;
  int hh = 0,tt = 0;
  q[0] = root;
  while (hh<=tt){
    int t = q[hh++];
    for(int i = h[t];~i;i = ne[i]){
      int j = e[i];
      if(depth[j]>depth[t]+1){
        depth[j] = depth[t]+1;
        q[++tt] = j;
        //当前节点j的父节点是t
        fa[j][0] = t;
        //迭代更新所有的父节点
        for(int k = 1; k <=15; k++) {
          fa[j][k] = fa[fa[j][k-1]][k-1];
        }
      }
    }
  }

}

void add(int a,int b){
  e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int lca(int a,int b){
  if (depth[a]<depth[b])
    swap(a,b);
  for(int i = 15; i >=0; i--) {
    //如果向上跳i层比b层数高，就可以跳
    if (depth[fa[a][i]]>=depth[b]){
      a = fa[a][i];
    }
  }
  //如果跳在了同一个点上，说明找到了公共祖先
  if (a==b) return a;

  //如果只是跳在了同一层
  for(int i = 15; i >=0; i--) {

    //没有跳出根节点
    if (fa[a][i]!=fa[b][i]){
      //就往上跳
      a = fa[a][i];
      b = fa[b][i];
    }
  }
  return fa[a][0];
}


int main(){
  cin>>n;
  memset(h,-1,sizeof h);

  int root = 0;
  for(int i = 0; i <n; i++) {
    int a,b;
    cin>>a>>b;
    if (b==-1) root = a;
    else{
      add(a,b);
      add(b,a);
    }

  }
  bfs(root);
//   for(int i = 0; i <=n; i++) {
//     for(int j = 0; j <16; j++) {
//       cout<<fa[i][j]<<' ';
//     }
//     cout<<endl;
//   }
  cin>>m;
  while (m -- )
  {
    int a, b;
    cin >> a >> b;
    int p = lca(a, b);
    if (p == a) cout << "1" << endl;
    else if (p == b) cout << "2" << endl;
    else cout << "0" << endl;
  }
}