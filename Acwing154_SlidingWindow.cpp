//
// Created by 95853 on 2021/7/23.
//
/**
* https://www.acwing.com/problem/content/156/
*/
#include "bits/stdc++.h"

using namespace std;
const int N = 100010;
int n, k, a[N], q[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]) ;
    }
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && q[hh] < i - k + 1) {
            hh++;
        }
        while (hh <= tt && a[q[tt]] > a[i]) {
            tt--;
        }
        q[++tt] = i;
        if (i > k - 1) {
            printf("%d ",a[q[hh]]);
        }
    }
    puts("");
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && q[hh] < i - k + 1) {
            hh++;
        }
        while (hh<=tt&&a[q[tt]]<a[i]){
            tt--;
        }
        q[++tt] = i;
        if (i>k-1){
            printf("%d ",a[q[hh]]);
        }
    }
}