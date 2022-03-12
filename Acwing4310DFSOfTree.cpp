//
// Created by 刘宇韬 on 2022/3/5.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,m;
//存先序遍历后的序列
vector<int>q;
//树的邻接表
vector<int> h[N];
//存节点值对应的位置
unordered_map<int ,int>mp;
//存每个节点子树的大小
int siz[N];
int dfs(int u){
  q.push_back(u);
  for(int i = 0; h[u].size() ; i ++) {
    siz[u]+= dfs(h[u][i]);
  }
  return siz[u];
}

int main()
{
  cin>>n>>m;
  memset(h,-1,sizeof h);
  for(int i = 1; i <=n; i++) {
    int p;
    cin>>p;
    h[p].push_back(i);
    siz[i] = 1;
  }
  siz[1] = 1;

  dfs(1);

  for(int i = 0; i <q.size(); i++) {
    cout<<q[i]<<' ';
    mp[q[i]] = i;
  }
  while (m--){
    int u,k;
    cin>>u>>k;
    if(k > siz[u]) cout << -1 << endl; // 如果k大于根节点子树的大小，无解
    else cout << q[mp[u] + k - 1] <<endl; // 否则输出答案
  }

}
