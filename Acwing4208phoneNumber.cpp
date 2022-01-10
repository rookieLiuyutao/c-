#include "bits/stdc++.h"
using namespace std;
// suffix存每个人所有电话的后缀，phone存每个人读入的所有电话，ans存答案
unordered_map<string, unordered_set<string>> suffix, ans, phone;

int n;
int main() {
  cin >> n;
  string name;
  int cnt;
  for (int i = 0; i < n; i++) {
    cin >> name >> cnt;
    //求出当前号码的所有后缀
    for (int j = 0; j < cnt; j++) {
      string num;
      cin >> num;
      phone[name].insert(num);
      for (int k = num.size() - 1; k > 0; k--) {
        string s = num.substr(k, num.size() - k);
        suffix[name].insert(s);
      }
    }
  }
  //遍历读入的号码池phone，如果号码在后缀池中没有出现过，就存入答案
  for (auto x : phone) {
    for (auto s : x.second) {
      if (suffix[x.first].count(s))
        continue;
      ans[x.first].insert(s);
      //一定要记得把当前号码也放入号码池
      suffix[x.first].insert(s);
    }
  }

  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first << ' ';
    cout << x.second.size() << ' ';
    for (auto s : x.second) {
      cout << s << ' ';
    }
    cout << endl;
  }
}
