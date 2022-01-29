#include "bits/stdc++.h"
using namespace std;
//为了方便遍历数的每一位，用string来存
string a, range;
unordered_set<int> q;

/**
 * 把n进制的x转换为10进制
 * 用到了秦九韶算法
 * @param n
 * @param x 为了方便遍历数的每一位，用string来存
 * @return
 */
int get(int n, string x) {
  int res = 0;
  for (auto c : x) {
    res = res * n + c - '0';
  }
  return res;
}

int main() {
  cin >> a >> range;
  for (int i = 0; i < a.size(); i++) {
    int x = a[i] - '0';
    if (x == 0) {
      a[i] = '1';
      q.insert(get(2, a));
      a[i] = '0';
    } else if (x == 1) {
      a[i] = '0';
      q.insert(get(2, a));
      a[i] = '1';
    }
  }
  //想要用增强for又能同时在遍历的时候改变原数组的值，加&
  for (auto &c : range) {
    char t = c;
    for (int i = 0; i < 3; i++)
      if (i + '0' != t) {
        c = i + '0';
        int x = get(3, range);
        if (q.count(x)) {
          cout << x << endl;
          return 0;
        }
      }
    c = t;
  }
}