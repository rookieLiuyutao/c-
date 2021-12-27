#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int m,n;
int w[500010];
struct Node{
    int l,r,tmax,lmax,rmax,sum;
}tr[500010*4];

void pushup(Node& u,Node& l,Node& r){
    u.sum = l.sum+r.sum;
    u.lmax = max(l.lmax,l.sum+r.lmax);
    u.rmax = max(r.rmax,l.rmax+r.sum);
    u.tmax = max(max(l.tmax,r.tmax),l.rmax+r.lmax);
}

void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r){
    if(l>=r) tr[u] = {l,r,w[r],w[r],w[r],w[r]};
    else{
        tr[u] = {l,r};
        int mid =(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

Node query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u];
    else
    {
        int mid = (tr[u].l+tr[u].r)>>1;
        if(r<=mid) return query(u<<1,l,r);
        else if(l>mid) return query(u<<1|1,l,r);
        else{
            Node res;
            auto left = query(u<<1,l,r), right = query(u<<1|1,l,r);
            pushup(res,left,right);
            return res;
        }
    }
}

void modify(int u,int x,int v){
    if(tr[u].l==x&&tr[u].r==x) tr[u] = {x,x,v,v,v,v};
    else{
        int mid = (tr[u].l+tr[u].r)>>1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

int main()
{
    cin >> n>>m;
    int k,x,y;
    for (int i = 1; i <= n; i ++ )cin>>w[i];
    build(1,1,n);
    while (m -- ){
        cin >> k>>x>>y;
        if(k==1){
            if(x>y)swap(x,y);
            cout << query(1,x,y).tmax<<endl;
        }else{
            modify(1,x,y);
        }
    }

}



