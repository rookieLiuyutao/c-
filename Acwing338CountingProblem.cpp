//
// Created by 刘宇韬 on 2022/3/16.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 2005;
LL dp[N][N];
int cnt,s[N];
int ans[10];
/**
 *
 * @param u 当前的数位
 * @param sum 当前该数出现的次数
 * @param x 当前该数
 * @param lead 是否当前在枚举首位
 * @param limit 是否枚举到当前可枚举的上界
 * @return
 */
LL dfs(int u,LL sum,int x,bool lead,bool limit){
  //递归到了叶子节点
  if (!u) return sum;
  //由于 dp[u][sum]!=-1 所以必然是递归完整棵树回溯的时候才能return
  if (lead && !limit && dp[u][sum]!=-1) return dp[u][sum];
  LL res = 0;
  //up表示当前这位数的枚举范围的上界，即枚举范围为[0,up],当没有限制的时候可以枚举[0,9],
  // 有限制的时候只能枚举[0,s[u]]
  int up = limit?s[u]:9;
  for(int i = 0; i <=up; i++) {
    //(lead|i)意思是在首位的时候不能填0，且要枚举到要统计的这个数，答案才能+1
    //limit&&(i==up)表示只有在(i==up)即正在枚举上界的时候，才会有限制，否则都是没有限制的
    res+=dfs(u-1,sum+((lead|i)&&( i == x)), x,lead|i,limit&&(i==up));
  }
  //对于当前递归的层来说，如果枚举到首位，且没有限制，说明回溯到了这一中间层，将当前层得到的答案记录
  if(lead&&!limit)dp[u][sum]=res;
  return res;
}

LL work(int n,int num){
  memset(dp,-1,sizeof dp);
  cnt = 0;
  while (n){
    s[++cnt] = n%10;
    n/=10;
  }
  return dfs(cnt,0,num, false, true);
}

int main(){
  int a,b;
  while (cin>>a>>b,a&&b){
    if (a>b)
      swap(a,b);
    //枚举每个数字
    for(int i = 0; i <=9; i++) {
      cout<<work(b,i)- work(a-1,i)<<' ';

    }

    cout<<endl;
  }
}    