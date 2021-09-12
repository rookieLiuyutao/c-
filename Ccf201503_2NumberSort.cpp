//
// Created by 95853 on 2021/8/16.
//
#include "bits/stdc++.h"

using namespace std;
const int N = 1010;
struct point {
    int x, y;

    bool operator<(const point &p) const {
        if (y != p.y)return x > p.x;
        return x < p.x;
    }
} q[N];
int a[N];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i <n; i++) {
      int x;
      cin>>x;
      a[x]++;
    }
    int cnt =0;
    for(int i = 0; i <N; i++) {
        if (a[i]){
            q[cnt++] = {i,a[i]};
        }
    }
    sort(q,q+cnt);
    for(int i = 0; i <cnt; i++) {
      cout<<q[i].x<<' '<<q[i].y<<endl;
    }
}