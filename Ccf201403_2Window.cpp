//
// Created by 95853 on 2021/8/12.
//
#include "iostream"
using namespace std;
const int N = 15;
struct p{
    int x1,y1,x2,y2,id;
} phone[N];
int n,m;

int get(int x,int y){
    for(int i = n; i >0; i--) {
        if (x>= phone[i].x1&&x<= phone[i].x2&&y>= phone[i].y1&&y<= phone[i].y2)return i;
    }
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i = 1; i <=n; i++) {
      cin>> phone[i].x1>> phone[i].y1>> phone[i].x2>> phone[i].y2;
      phone[i].id = i;
    }
    while (n--){
        int x,y;
        cin>>x>>y;
        int t = get(x,y);
        if (t==0){
            puts("IGNORED");
        } else{
            cout<< phone[t].id<<endl;
            auto r  = phone[n];
            for(int i = t; i <n; i++) {
              phone[i] = phone[i+1];
            }
            phone[n] = r;
        }
    }
}