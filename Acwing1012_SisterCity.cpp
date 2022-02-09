
/**
 * @see 线性dp 最长上升子序列
 * https://www.luogu.com.cn/problem/P2782
 */


#include "bits/stdc++.h"
using namespace std;
#define r first
#define l second
const int N = 5010;
int n, q[N];
pair<int ,int >c[N];

int main(){
    scanf("%d",&n);
    int res = 0;
    for(int i = 0; i <n; i++) {
        scanf("%d%d",&c[i].r,&c[i].l);
    }
    sort(c,c+n);
    for(int i = 0; i <n; i++) {
      int l = 0,r = res;
        while (l<r){
            int mid = (l+r+1)>>1;
            if(q[mid]<c[i].l){
                l = mid;
            } else{
                r = mid-1;
            }
        }
        q[l+1] = c[i].l;
        res = max(res,l+1);
    }
//    for(int i = 0; i <n; i++) {
//      cout<<c[i].x<<' '<<c[i].y<<endl;
//    }
    printf("%d",res);
}