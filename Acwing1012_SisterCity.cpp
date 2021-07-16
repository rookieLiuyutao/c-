
/**
 * @see 线性dp 最长上升子序列
 * https://www.luogu.com.cn/problem/P2782
 */


#include "bits/stdc++.h"
using namespace std;
#define x first
#define y second
const int N = 5010;
int n,s[N];
pair<int ,int >c[N];

int main(){
    scanf("%d",&n);
    int res = 0;
    for(int i = 0; i <n; i++) {
        scanf("%d%d",&c[i].x,&c[i].y);
    }
    sort(c,c+n);
    for(int i = 0; i <n; i++) {
      int l = 0,r = res;
        while (l<r){
            int mid = (l+r+1)>>1;
            if(s[mid]<c[i].y){
                l = mid;
            } else{
                r = mid-1;
            }
        }
        s[l+1] = c[i].y;
        res = max(res,l+1);
    }
//    for(int i = 0; i <n; i++) {
//      cout<<c[i].x<<' '<<c[i].y<<endl;
//    }
    printf("%d",res);
}