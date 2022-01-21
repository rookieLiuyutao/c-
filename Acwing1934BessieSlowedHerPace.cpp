/**
 * https://www.acwing.com/problem/content/1936/
 */
#include "bits/stdc++.h"
using namespace std;
const int N = 10010;
vector<int> times, len;
int m;
int main() {
  char op;
  int x;
  while (m--) {
    cin >> op >> x;
    if (op == 'T')
      times.push_back(x);
    else
      len.push_back(x);
  }
  sort(times.begin(), times.end());
  sort(len.begin(), len.end());
  double t = 0,s = 0,v = 1;
  int i = 0,j = 0;
  while (i<times.size()||j<len.size()){
    if (j==len.size()||(i<times.size()&&times[i]-t<(len[j]-s)*v)){
      s+=(times[i]-t)/v;
      t = times[i];
      v++;i++;
    }else{
      t+=(len[j]-s)*v;
      s = len[j];
      v++;j++;
    }

  }
  printf("%.1f",t);

}
