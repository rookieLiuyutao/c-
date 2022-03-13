#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 110,M = 2*N;
int n;
vector<int >h[N];
int a[N];

void dfs(int u){
  if (u<=1) return;
  h[u].push_back(a[u*2]);
  h[u].push_back(a[u*2+1]);
  dfs(u+1);
}

void dfsd(int u){

}

int main(){
  cin>>n;
  for(int i = 1; i <=n; i++) {
    cin>>a[i];
  }
  dfs(1);

}    
