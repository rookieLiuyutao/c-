/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define pb push_back
#define fi first
#define se second
class Solution {
public:
  vector<long long> kthPalindrome(vector<int>& q, int n) {
      vector<long long >res;
      for(auto x: q){
        //分奇偶：如果长度为4，应该补2个0，长度为3，应补1个0
        int k = (n+1)/2;
        int p = pow(10,k-1);
        if (x>9*p){
          res.push_back(-1);
        }else{
          //求左半边第x小的数
          long long t = p+x-1;
          //转化为字符串，通过翻转得到右边
          auto before = to_string(t);
          auto after = to_string(t);
          //奇数反转前要去掉最后一位
          if (n%2)after.pop_back();
          reverse(after.begin(), after.end());
          res.push_back(stoll(before+after));
        }
      }
      return res;
  }
};