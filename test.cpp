/**
 * @author ´ó²Ë¹·
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
  typedef long long LL;

  bool check(int t,vector<int>& candies,long long k){
    LL sum = 0;
    for(auto x:candies){
      sum+=x;
    }
    if ((LL) t*k>sum) return false;
    int n = candies.size();

    int x = lower_bound(candies.begin(), candies.end(),t)-candies.begin();
    if (x==0) return candies[0]>=t;
    int cnt = n-x-1;
    if (x>n-1) return false;

      if (candies[n-1]/(cnt)>=t) return true;

    return false;
  }

  int maximumCandies(vector<int>& candies, long long k) {
      LL sum = 0;
      for(auto x:candies){
        sum+=x;
      }
      if (sum>k) return 0;
      sort(candies.begin(), candies.end());
      int l = 0,r = 1e9;
      while (l<r){
        int mid = (l+r)>>1;
        if (check(mid,candies,k)){
          r = mid;
        }else{
          l = mid+1;
        }
      }
      return l;
  }
};

int main(){

}