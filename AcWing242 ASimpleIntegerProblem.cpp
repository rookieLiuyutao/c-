#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;
int a[N],n,m;
LL tr[N];
void add (int x,int c){
  for(int i = x;i<=n;i+=(i&-i))tr[i]+=c;
}
LL sum(int x){
  LL res = 0;
  for(int i = x;i;i-=(i&-i))res+=tr[i];
  return res;
}
int main(){
  cin>>n>>m;
  for(int i = 1;i<=n;i++)cin>>a[i];
  for(int i = 1;i<=n;i++)add(i,a[i]-a[i-1]);
  char op;
  int l,r,d,x;
  while(m--){
    cin>>op;
    if(op=='C'){
      cin>>l>>r>>d;
      add(l,d);
      add(r+1,-d);
    }else{
      cin>>x;
      cout<<sum(x)<<endl;
    }
  }
}