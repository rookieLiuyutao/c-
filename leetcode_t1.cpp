/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
//std::ios::sync_with_stdio(false);
typedef pair<int,int> PII;
#define pb push_back
#define fi first
#define se second
class Solution {
public:
  int minDeletion(vector<int>& nums) {

      if (nums.size()==0) return 0;
      int res = 0;
      for(int i = 0; i <nums.size(); i++) {
        if ((i-res)%2==0){
          if (i+1<nums.size()&&nums[i]==nums[i+1]) {
            res++;

          }
        }
      }
      if ((nums.size()-res)%2)res++;
      return res;
  }
};