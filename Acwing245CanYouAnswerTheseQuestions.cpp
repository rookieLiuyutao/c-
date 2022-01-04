#include<iostream>
using namespace std;
const int N = 500010;
int n,m,w[N];
struct Node{
    int l,r;
    int sum,tm,lm,rm;
}tr[4*N];
//一定要记住开4倍的空间
void pushup(Node& u,Node& l,Node &r){
    u.sum = l.sum+r.sum;
    u.lm = max(l.lm,l.sum+r.lm);
    u.rm = max(r.rm,r.sum+l.rm);
    u.tm = max(l.rm+r.lm,max(l.tm,r.tm));
    //一定要想清楚每一种情况
}
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l==r){
        tr[u]={l,r,w[l],w[l],w[l],w[l]};
    }else{
        int mid = (l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
        //一定要记住pushup
    }
}

void modify(int u,int x,int v){
    if(tr[u].l==tr[u].r){
        tr[u] = {x,x,v,v,v,v};
    }else{
        int mid = (tr[u].l+tr[u].r)>>1;
        if(x<=mid)modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
        //一定要记住pushup
    }

}

Node query(int u,int l,int r){
    //要查到的区间要覆盖树的区间才算查到
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u];
    }else{
        int mid = (tr[u].l+tr[u].r)>>1;
        //---------------------------------------
        //这两句一定要记住写return
        if(r<=mid)return query(u<<1,l,r);
        else if(l>mid) return query(u<<1|1,l,r);
        //---------------------------------------
        else{
            Node res;
            auto left = query(u<<1,l,r),right = query(u<<1|1,l,r);
            pushup(res,left,right);
            return res;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i =1;i<=n;i++)cin>>w[i];
    int k,x,y;
    //一定要在读入w[N]之后build，build会用到w[N]的值
    build(1,1,n);
    while(m--){
        cin>>k>>x>>y;
        if(k==1){
            if(x>y)swap(x,y);
            cout<<query(1,x,y).tm<<endl;
        }else{
            modify(1,x,y);
        }
    }
}

