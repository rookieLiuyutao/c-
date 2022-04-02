//
// Created by 刘宇韬 on 2022/3/30.
//
/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define pb push_back
#define fi first
#define se second
const int N = 500010;
int a[N];
int n;
long double sum;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> sum;
  long double avg = sum*1.0 / n;
  int clow = 0,low = 0;
  double ls = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a,a+n);

  long double res = 0;
  long double newAvg = avg;
  for (int i = 0; i < n; i++) {
    if (a[i]<=newAvg){
      sum-=a[i];
      res+=pow(avg-a[i],2);
      newAvg = sum*1.0/(n-i-1);
    }else{
      res+=pow(newAvg-avg,2);
    }
  }
  printf("%.4lf", sqrt(res/n));
}