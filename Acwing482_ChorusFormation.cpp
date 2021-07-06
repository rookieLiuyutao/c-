/**
 * @see 线性dp 最长上升子序列
 * https://www.acwing.com/problem/content/description/484/
 */

#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n,r[N],l[N],h[N];

int main(){
    cin>>n;
    int res = 1;
    for (int i = 0; i < n; i++) {
        cin>>h[i];
        l[i] = 1;
        r[i] = 1;
        for (int j = 0; j < i; j++) {
            if (h[i] > h[j]) {
                l[i] = max(l[i], l[j] + 1);
            }
            //如果max取了dpl[j] + 1，说明往上走的序列更长，队伍还在往上走；
            //如果max取了dpr[j] + 1，说明往下走的序列更长，队伍还在往下走；
            //同时扩展时，结果较大的一个就是最终结果
            if (h[i] < h[j]) {
                r[i] = max(r[i], max(r[j] + 1, l[j] + 1));
            }
        }
        res = max(res, max(r[i], l[i]));
    }
    cout<<n-res<<endl;

}