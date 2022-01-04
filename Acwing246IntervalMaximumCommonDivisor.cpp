#include "iostream"
using namespace std;
const int N = 500005;
typedef long long LL;
int n,m;
LL w[N];
struct Node{
  int l,r;
  //需要存的额外信息有，1.区间和 2.区间的最大公约数
  LL sum ,d;
}tr[4*N];

//思路：
//在树的每个叶子节点中，存下相邻两树的差d，再存下区间和
//这样给一个区间加上一个数，可以利用差分优化为改变2个点的值
//差分数组求源数组的过程就是区间中每个点d的和，即为区间和
//回溯的时候，因为因为 gcd(a,b)=gcd(a,b−a)

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
  if(l==r) {
    //存下相邻两个数的差
    LL d = w[r]-w[l-1];
    tr[u] = {l,r,d,d};
  }else {

    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }
}

void modify(int u,int x,LL v){
  if(tr[u].l==tr[u].r){
    //求前缀和的过程
    LL sum = tr[u].sum+v;
    tr[u].sum = sum;
    tr[u].d = sum;
  }else{
    int mid = (tr[u].l+tr[u].r)>>1;
    if (x<=mid) modify(u<<1,x,v);
    else modify(u<<1|1,x,v);
    pushup(u);
  }

}
Node query(int u,int l,int r){
  if (tr[u].l>=l&&tr[u].r<=r)return tr[u];
  int mid = (tr[u].l+tr[u].r)>>1;
  if (r<=mid) return query(u<<1,l,r);
  else if(l>mid) return query(u<<1|1,l,r);
  else{
    Node res;
    auto left = query(u<<1,l,mid),right = query(u<<1|1,mid+1,r);
    pushup(res,left,right);
    return res;
  }
}

int main(){
  cin>>n>>m;
  for(int i = 1; i <=n; i++) {
    cin>>w[i];
  }
  build(1,1,n);
  int l,r;
  LL d;
  char op;
  while (m--){
    cin >> op;
    if (op=='Q'){
      cin>>l>>r;
      Node left = query(1,1,l),right({0,0,0,0});
      if(l+1<=r)right = query(1,l+1,r);
      //这里sum就是由差分数组的每一项求前缀和求出的原数组对应的一项
      LL res = abs(gcd(left.sum,right.d));
      cout<<res<<endl;
    }else if(op=='C'){
      cin>>l>>r>>d;
      //原数组a[l...r]+d,相当于 w[r+1]-d,w[l]+d;
      modify(1,l,d);
      if(r+1<=n)modify(1,r+1,-d);
    }
  }
}