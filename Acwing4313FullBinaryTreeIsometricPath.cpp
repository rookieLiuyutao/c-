//
// Created by 刘宇韬 on 2022/3/13.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
/**
 * 题中给的数据范围是树有10层
 * 我们发现，想要满足要求，那么最后一层某节点到叶子节点的左右儿子路径长度一定相等
 * 那么只要贪心的把每一层的左右路径[增加到相等]，一定是最优解
 */
const int N = (1<<10)+5;
int w[N];
int n,res;

int dfs(int u){
  if (u*2>(1<<(n+1))-1){
    return 0
  }
  int l = dfs(u*2)+w[u*2];
  int r = dfs(u*2+1)+w[u*2+1];
  res+= abs(l-r);
  return max(l,r);
}

int main(){
  cin>>n;
  for(int i = 2; i <=(1<<(n+1))-1; i++) {
    cin>>w[i];
  }
  dfs(1);
  cout<<res;
}    