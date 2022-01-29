// Created by 95853 on 2022/1/22.
/*
 *
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
int p[N], cnt;
bool range[N];

int main() {
  //预处理出所有的质数
  for (int i = 2; i < N; i++) {
    if (!range[i])
      p[cnt++] = i;
    for (int j = 0; p[j] * i < N - 1; j++) {
      range[p[j] * i] = true;
      if (i % p[j] == 0)
        break;
    }
  }

  int n;
  while (cin>>n,n){
    for(int i = 1; ; i++) {
      int a = p[i],b = n-a;
      if (!range[b]){
        printf("%d = %d + %d",n,a,b);
        break;
      }
    }
  }

}
