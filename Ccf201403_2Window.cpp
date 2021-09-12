//
// Created by 95853 on 2021/8/12.
//
#include "iostream"
using namespace std;
const int N = 15;
struct p{
    int x1,y1,x2,y2,id;
} p[N];
int n,m;

int get(int x,int y){
    for(int i = n; i >0; i--) {
        if (x>=p[i].x1&&x<=p[i].x2&&y>=p[i].y1&&y<=p[i].y2)return i;
    }
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i = 1; i <=n; i++) {
      cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
      p[i].id = i;
    }
    while (n--){
        int x,y;
        cin>>x>>y;
        int t = get(x,y);
        if (t==0){
            puts("IGNORED");
        } else{
            cout<<p[t].id<<endl;
            auto r  = p[n];
            for(int i = t; i <n; i++) {
              p[i] = p[i+1];
            }
            p[n] = r;
        }
    }
}