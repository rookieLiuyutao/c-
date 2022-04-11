#include<iostream>
using namespace std;
//int cnt[10]; 
int main()
{
  int cnt[10] = {0}; //计数器，存入1~9卡片的使用次数，并赋予初始值0 (也可以放全局变量如上所示，c++全局变量默认值为0)
  int count = 2021;//每种卡片2021张
  int a;//a为最终求的数
  for(int i = 1; ; i ++ )//循环终止条件在后面判断
  {
    int n=i;
    while(n)
    {
      cnt[n % 10] ++;
      n /= 10;
    }
    if(cnt[1] > count) //模拟了几组数发现1卡片一定是最先不够用的，所以如果1卡片的个数超范围时停止循环
    {
      a = i-1; //要注意这个数是拼不成的，就如题例中的11，所求结果要是当前数减去1
      break;
    }
  }
  cout << a << endl; //输出即可
  return 0;
}
