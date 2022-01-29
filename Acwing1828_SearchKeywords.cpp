//
// Created by 95853 on 2021/9/4.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n,ne[N],tr[N][26],cnt[N],q[N],idx;
string q,text;
void insert(){
    int p = 0;
    for(int i = 0;i< q.size();i++){
        int t = q[i]-'a';
        if(!tr[p][t])tr[p][t] = ++idx;
        p = tr[p][t];
    }
    cnt[p]++;
}
void build(){
    int hh = 0,tt = -1;
    for(int i = 0;i<26;i++){
        if(tr[0][i])q[++tt] = tr[0][i];
    }
    while(hh<=tt){
        int t = q[hh++];
        for(int i = 0; i <26; i++) {
          int p = tr[t][i];
            if (!p){
                tr[t][i] = tr[ne[t]][i];
            }else{
                ne[p] = tr[ne[t]][i];
                q[++tt] = p;
            }
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(tr,0,sizeof tr);
        memset(ne,0,sizeof ne);
        memset(cnt,0,sizeof cnt);
        idx = 0;
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>> q;
            insert();
        }
        int res = 0;
        build();
        cin>>text;
        for(int i = 0,j = 0;i<text.size();i++){
            int t = text[i]-'a';
            j = tr[j][t];
            int p = j;
            while(p){
                res+=cnt[p];
                cnt[p] = 0;
                p = ne[p];
            }
        }
        cout<<res;
    }
}
