#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maximumTop(vector<int>& a, int k) {
    int n = a.size();
    if (n==1&&k>=1)return -1;
    int maxv = -1;
    if (k>n){
      for(int i = 0; i <n; i++) {
        maxv = max(maxv,a[i]);
      }
    }else{
      for(int i = 0; i <k; i++) {
        maxv = max(maxv,a[i]);
      }
    }
    return maxv;
  }
};