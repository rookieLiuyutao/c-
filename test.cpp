#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
struct Node{
    int l,r,v;
}tr[4*N];
int m,mod;
void pushup(int u){
    tr[u].v = max(tr[u<<1].v,tr[u<<1|1].v);
}
void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l==r)return ;
    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}
int query(int u,int l,int r){
    if(l<=tr[u].l&&r>=tr[u].r)return tr[u].v;

    int mid = (tr[u].l+tr[u].r)>>1;
    int res = 0;
    if(l<=mid)res = query(u<<1,l,r);
    if(r>mid)res = max(query(u<<1|1,l,r),res);
    return res;
}
void modfiy(int u,int x,int v){
    if(tr[u].l==x&&tr[u].r==x) {
        tr[u].v = v;
    }else{
        int mid = (tr[u].l+tr[u].r)>>1;
        if(x<=mid) modfiy(u<<1,x,v);
        else modfiy(u<<1|1,x,v);
        pushup(u);
    }

}

int main(){
    cin>>m>>mod;
    int n = 0,t= 0,x;
    build(1,1,m);
    char op;
    while(m--){
        cin>>op>>x;
        if(op=='Q'){
            t = query(1,n-x+1,n);
            cout<<t<<endl;
        }else{
            modfiy(1,n+1,(t+x)%mod);
            n++;
        }
    }
}