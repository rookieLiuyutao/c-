//
// Created by 95853 on 2022/1/30.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010, INF = 1e9 + 7;
typedef pair<int, int> PII;
#define r first
#define l second
int a[N];
PII b[N];
void generateRandomArray(int n, int rangeL, int rangeR) {
  srand(time(NULL)); // 随机种子
  for (int i = 0; i < n; i++)
    a[i] = rand() % (rangeR - rangeL + 1) + rangeL;
}
void generateRandomPairArray(int n, int rangeL, int rangeR) {
  srand(time(NULL)); // 随机种子
  for (int i = 0; i < n; i++) {
    b[i].r = rand() % (rangeR - rangeL + 1) + rangeL;
    b[i].l = rand() % (rangeR - rangeL + 1) + rangeL;
  }
}
int main() {
  int n = 10;
  cout << "排序前：";
  generateRandomArray(n, 1, 9);
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  puts("");
  sort(a, a + n);
  cout << "排序后:";
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  puts("");
  //第一个大于等于5的数的下标
  cout << upper_bound(a, a + n, 5) - a << endl;
  //第一个小于等于5的数的下标
  cout << lower_bound(a, a + n, 5) - a << endl;

  for (int i = 0; i < 9; i++) {
    b[i] = {i, i + 1};
  }
  //    generateRandomPairArray(n, 1, 9);
  cout << "pair数组排序前:";
  for (int i = 0; i < n - 1; i++) {
    cout << b[i].r << ' ' << b[i].l << endl;
  }
  b[n - 1] = {5, 8};
  puts("");
  sort(b, b + n);
  cout << "pair数组排序后:";
  for (int i = 0; i < n; i++) {
    cout << b[i].r << ' ' << b[i].l << endl;
  }
  b[n - 1] = {5, 8};
  puts("");
  //在从小到大的排序数组中，lower_bound(
  //begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num
  auto p1 = upper_bound(b, b + n, make_pair(5, 7));
  auto p2 = upper_bound(b, b + n, make_pair(5, INF));
  //在从小到大的排序数组中，upper_bound(
  //begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，
  auto p3 = lower_bound(b, b + n, make_pair(5, 7));
  auto p4 = lower_bound(b, b + n, make_pair(5, -INF));
  cout << p1->r << ' ' << p1->l << endl;
  cout << p2->r << ' ' << p2->l << endl;
  cout << p3->r << ' ' << p3->l << endl;
  cout << p4->r << ' ' << p4->l << endl;


  reverse(b, b + n);
  cout<<"从大到小排序："<<endl;
  for (int i = 0; i < n - 1; i++) {
    cout << b[i].r << ' ' << b[i].l << endl;
  }
  //在从小到大的排序数组中，lower_bound(
  //begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num
  auto p5 = upper_bound(b, b + n, make_pair(5, 7),greater<PII>());
  auto p6 = upper_bound(b, b + n, make_pair(5, INF),greater<PII>());
  //在从小到大的排序数组中，upper_bound(
  //begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，
  auto p7 = lower_bound(b, b + n, make_pair(5, 7),greater<PII>());
  auto p8 = lower_bound(b, b + n, make_pair(5, -INF),greater<PII>());
  cout << p5->r << ' ' << p5->l << endl;
  cout << p6->r << ' ' << p6->l << endl;
  cout << p7->r << ' ' << p7->l << endl;
  cout << p8->r << ' ' << p8->l << endl;
}