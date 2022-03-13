#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1e5+5;
int n,m,q;
string s,p;

int ne[N];
bool st[N];
int sum[N];
int main(){
  cin>>n>>m>>q;
  cin>>s>>p;
//   cout<<s<<' '<<p;
  p = "0" + p;
  s = "0" + s;
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && p[j + 1] != p[i]) j = ne[j];
    if (p[j + 1] == p[i]) j++;
    ne[i] = j;
  }
  for (int i = 1, j = 0; i <= n; i++) {
    while (j && p[j + 1] != s[i]) j = ne[j];
    if (p[j + 1] == s[i]) j++;
    if (j == m) {
      st[i-j] = true;
      j = ne[j];
    }
  }
  for(int i = 1; i <=n; i++) {
    sum[i] = sum[i-1]+st[i];
    // cout << st[i]<<' ';
    // cout<<sum[i]<<' ';
  }
  while (q--){
    int l,r;
    cin>>l>>r;
    if (r-l+1<m){
      cout<< 0<<endl;
    }else{
      cout<<sum[r-m+1]-sum[l-1]<<endl;
    }
  }
}    
