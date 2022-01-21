/*
 * https://www.acwing.com/problem/content/1962/
 */
#include "bits/stdc++.h"
using namespace std;
const int N = 20;
typedef long long LL;
int n,q, a[N];
LL m;
//map存一条记录和它出现的时刻
unordered_map<int,int> q;

/**
 * 模拟每一步灯的变化的函数
 * @param x
 * @return
 */
int change(int x){
  int res = 0;
  //特判第一位，第一位的前一位是最后一位
  int p0 = x&1;
  if (p0==1){
    //1变成0，0变成1用异或
    res+=(((x>>(n-1))&1)^1)<<(n-1);
  }else{
    res+=((x>>(n-1))&1)<<(n-1);
  }

  for(int i = n-1; i >0; i--) {
    int p =x>>i&1;
    if (p==1){
      res+=(((x>>(i-1))&1)^1)<<(i-1);
    }else{
      res+=((x>>(i-1))&1)<<(i-1);
    }
  }
  return res;
}

/**
 * 把十进制数变为2进制数
 * @param x
 */
void rechange(int x){
  for(int i = n-1; i >=0; i--) {
    cout<<(x>>i&1)<<endl;
  }
}

int main() {
  cin >> n >> m;
  //将读入的二进制数压缩成一个10进制数q
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    q += (a[i] << (n - i - 1));
  }
  //t为全局时间，r为环的大小
  int t = 0,r = 0;
  int p = q;
  while (t<m){
    p = change(p);
    //如果p没有在集map里出现过，就放入map；出现过就表明找到了一个环
    if (!q.count(p)){
      q.insert({p,t++});
    } else{
      //记录环的长度
      r = t- q[p]-1;
      break;
    }
  }
  //如果还没有找到环时间就到了
  if (r==0){
    rechange(p);
  } else{
    //取余时间
    LL c = (m-t)%r;
    int start = q[p];
    //在map里找到取余后的时间
    for(auto i: q){
      if (i.second==start+c){
        rechange(i.first);
        break;
      }
    }
  }
}
