#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
/**
 * https://www.acwing.com/problem/content/description/4398/
 * 思路：
 * 首先，不用把矩阵构造出来，子矩阵的面积和就是2个数组区间和的乘积
 * 预处理出每个区间长度下，区间和的最小值
 * 枚举区间每个长度，算出结果
 */
const int N = 2005;
int n,m;
int s1[N],s2[N];
int a[N],b[N];
int main(){
  cin>>n>>m;
  for(int i = 1; i <=n; i++) {
    int x;
    cin>>x;
    s1[i] = s1[i-1]+x;
  }
  for(int i = 1; i <=m; i++) {
    int x;
    cin>>x;
    s2[i] = s2[i-1]+x;
  }
  int limit;
  cin>>limit;
  //枚举每个区间长度
  memset(a,0x3f,sizeof a);
  memset(b,0x3f,sizeof b);
  for(int i = 1; i <=n; i++) {
    for(int j = 1; j+i-1 <=n; j++) {
      a[i] = min(s1[j+i-1]-s1[j-1],a[i]);
    }
  }
  for(int i = 1; i <=m; i++) {
    for(int j = 1; j+i-1 <=m; j++) {
      b[i] = min(s2[j+i-1]-s2[j-1],b[i]);
    }
  }
  int ans = 0;
  for(int i = n; i; i--) {
    for(int j = m; j ; j--) {
      //注意这里相乘会报int
      if ((LL)a[i]*b[j]<=limit){
        ans = max(ans,i*j);
      }
    }
  }
  cout<<ans;
}