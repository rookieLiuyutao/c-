//
// Created by 刘宇韬 on 2022/4/7.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 15;
int dp[N][N];
int n,m;
int res;
/**
 *
 * @param last 当前层还剩下多少能量
 * @param depth 当前到了第几层
 * @param min_power 因为不考虑顺序，所以要从小往大分配能量，从而避免重复
 */
void dfs(int last,int depth,int min_power){
  if (last==0&&depth>=n){
    //如果走到最后一层，且能量刚好用完，就是一种方案
    res++;
    return;
  }
  //到了最后一层，能量没有刚好用完，不是合法方案
  if (depth>=n) return;
  for(int i = min_power; i <=last; i++) {
    dfs(last-i,depth+1,i);
  }
}


int main(){
  int T;
  cin>>T;
  while (T--){
    res = 0;
    cin>>m>>n;
    dfs(m,0,0);
    cout<<res<<endl;
  }
}