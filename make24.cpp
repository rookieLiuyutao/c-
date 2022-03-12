#include "bits/stdc++.h"
using namespace std;
const int N = 100,eps = 1e-5;
int n;
double a[N];

bool st[N];
bool dfs(int u,double x){
  if (u>=n){
    return false;
  }
  if (x-24<eps){
    return true;
  }
  st[u] = true;
  if (st[u]){
    dfs(u+1,a[u]+x);
    dfs(u+1,a[u]-x);
    if (x==0){
      x=1;
    }
    dfs(u+1,a[u]*x);
    dfs(u+1,a[u]/x);
    st[u] = false;
  }
  return false;
}

int main(){
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>a[i];

  }
  for(int i = 0; i <n; i++) {
    swap(a[i],a[0]);
    if(!dfs(0,0)){
      cout<<"不能";
      return 0;
    }
    swap(a[i],a[0]);

  }
  cout<<"可";


}