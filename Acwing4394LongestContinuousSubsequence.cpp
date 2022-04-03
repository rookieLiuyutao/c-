/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
/**
 * https://www.acwing.com/problem/content/4397/
 * 思路：
 * 看到连续子区间，和最值，应该联想到滑动窗口
 * 要求该子序列包含不超过 k 个不同的值，想到应该用map维护窗口，但本题map会卡常，用hsah数组代替
 *
 */
const int N = 500005, M = 1000005;
int n,k;
//cnt即为维护窗口的hash数组
int a[N],cnt[M];
int main(){
  std::ios::sync_with_stdio(false);
  scanf("%d%d",&n,&k);
  for(int i = 1; i <=n; i++) {
    scanf("%d",&a[i]);
  }
  int res = 0;
  int l,r;
  //i是窗口右端点的指针，j是左端点指针，t维护当前窗口中有多少不同的元素
  for(int j = 1,i = 1,t = 0; i <=n; i++) {
    //先将当前遍历元素无脑加入窗口
    if (cnt[a[i]]==0) t++;
    cnt[a[i]]++;
    //当新加入的元素使窗口溢出时,就无脑把左边的元素丢掉
    while (t>k){
      if (cnt[a[j]]==1) t--;
      cnt[a[j]]--;
      j++;
    }
    //更新答案
    if (i-j+1>res){
      res = i-j+1;
      l = j;
      r = i;
    }
  }
  printf("%d %d",l,r);
}