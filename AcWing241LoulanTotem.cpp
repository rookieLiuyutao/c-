#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200010;
int g[N],l[N],a[N],tr[N];
int n;
int lb(int x){
  return x&-x;
}
void add(int x,int c){
  for(int i= x;i<=n;i += lb(i)){
    tr[i]+=c;
  }
}
int sum(int x){
  int res = 0;
  for(int i = x;i;i -= lb(i)){
    res+=tr[i];
  }
  return res;
}
int main(){
  cin>>n;
  for(int i = 1;i<=n;i++)cin>>a[i];
  for(int i = 1;i<=n;i++){
    int y = a[i];
    g[i] = sum(n)-sum(y);
    l[i] = sum(y-1);
    add(y,1);
  }
  memset(tr,0,sizeof tr);
  LL res1 = 0,res2 = 0;
  for(int i = n;i ;i--){
    int y = a[i];
    res1+=g[i]*(LL)(sum(n)-sum(y));
    res2+=l[i]*(LL)(sum(y-1));
    add(y,1);
  }
  cout<<res1<<' '<<res2;
}

