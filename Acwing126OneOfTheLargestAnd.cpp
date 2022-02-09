//
// Created by 刘宇韬 on 2022/2/2.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 105;
int n;
int a[N][N],s[N][N],b[N],f[N];
int get(int x1,int y1,int x2,int y2){
  return s[x2][y2]-s[x2][y1-1]-s[x2-1][y2]+s[x1-1][y1-1];
}
int main(){
  cin>>n;
  //预处理二维前缀和
  for(int i = 1; i <=n; i++) {
    for(int j = 1; j <=n; j++) {
      cin>>a[i][j];
      //后面只用到每一列的前缀和
      s[i][j] = s[i][j-1]+a[i][j];
    }
  }
  int res = -1e9;
  //枚举上界
  for(int i = 1; i <=n; i++) {
    //枚举下界
    for(int j = i; j <=n; j++) {
      int sum = 0;
      //枚举上下界中的每一列
      for(int k = 1; k <=n; k++) {
        //将上下界之间的一列数压缩成一个数
        int p = s[k][j]-s[k][i-1];
        sum+=p;
        res = max(res,sum);
        if (sum<0)sum = 0;
      }
    }
  }
  cout<<res;


}