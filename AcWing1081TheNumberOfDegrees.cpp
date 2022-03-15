//
// Created by 刘宇韬 on 2022/3/14.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;

/**
 * 题意：求给定区间 [X,Y]中 B进制的数的个数，该数满足：
 * 1.转化为B进制数后，只有k个1
 * 2.且除了上面的k位1，其他位全部为0
 * 2.且互不相等
 *
 * 划分：对于每一位有3种情况：
 * 该位填的数为1
 * 该位填的数为0：其他位上，就一共要有k位为1
 * 该位数上填的数为除0,1外的其他数，这种情况不合题意
 */

const int N = 35;
int x,y,k,b;
int C[N][N];
/**
 * 求在区间[0,n]中满足要求的数的个数
 * @param n
 * @return
 */
int work(int n ){
  //特判边界
  if (n==0)return 0;
  //所有满足要求的数，各个位只可能是0或1
  vector<int>s;
  //将B进制的每一位存在数组中
  while (n!=0){
    s.push_back(n%b);
    n/=b;
  }
  //在区间[0,n]中满足要求的数的个数
  int res = 0;
  //存前缀中有几位为B-1
  int last = 0;
  //从大往小枚举每一位
  for(int i = s.size()-1; i >=0; i--) {
    int &x = s[i];

    if (x){
      //这里也就是存last的原因：当前枚举到这一位，不知道前面枚举中有几位填了1
      res+=C[i][k-last];
      //不合法的情况，含了除0,1外的其他数
      if (x > 1)
      {
        if (k - last - 1 >= 0) res += C[i][k - last - 1];
        break;
      }else{
        //该位填的数为1
        last++;
        if (last>k)break;
      }
    }
    if (!i && last == k) res ++ ;

  }
  return res;
}


int main(){
  cin>>x>>y>>k>>b;
  //预处理组合数
  for(int i = 0; i <N; i++) {
    for(int j = 0; j <=i; j++) {
      if (!j) C[i][j] = 1;
      else C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
  }

  cout<<work(y)- work(x-1)<<endl;
}    