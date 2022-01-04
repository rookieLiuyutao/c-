#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
typedef long long LL;
int n,m;
LL w[N];
struct Node{
  int l,r;
  LL sum,d;
}tr[4*N];

LL gcd(LL a,LL b){
  return b?gcd(b,a%b):a;
}

void pushup(Node& u,Node& l,Node& r){
  u.sum = l.sum+r.sum;
  u.d = gcd(l.d,r.d);
}
void pushup(int u){
  pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r){
  tr[u] = {l,r};
  if(l==r){
    LL d = w[r]-w[l-1];
    tr[u] = {l,r,d,d};
  }
  else{
    int mid = l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
  }
}
void modify(int u,int x,LL v){
  if(tr[u].l==tr[u].r){
    LL sum = tr[u].sum+v;
    tr[u].sum = sum;
    tr[u].d = sum;
  }
  else{
    int mid = tr[u].l+tr[u].r>>1;
    if(x<=mid)modify(u<<1,x,v);
    else modify(u<<1|1,x,v);
    pushup(u);
  }
}
Node query(int u,int l,int r){
  if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
  int mid = tr[u].l+tr[u].r>>1;
  if(r<=mid)return query(u<<1,l,r);
  else if(l>mid)return query(u<<1|1,l,r);
  else{
    Node res;
    auto left = query(u<<1,l,mid),right = query(u<<1|1,mid+1,r);
    pushup(res,left,right);
    return res;
  }
}

int main(){
  cin>>n>>m;
  for(int i = 1;i<=n;i++)cin>>w[i];
  build(1,1,n);
  LL d;
  int l,r;
  char op;
  while(m--){
    cin>>op;
    if(op=='Q'){
      cin>>l>>r;
      Node left = query(1,1,l),right({0,0,0,0});
      if(l+1<=r)right = query(1,l+1,r);
      LL res = abs(gcd(left.sum,right.d));
      cout<<res<<endl;
    }else if(op=='C'){
      cin>>l>>r>>d;
      modify(1,l,d);
      if(r+1<=n)modify(1,r+1,-d);
    }
  }
}


