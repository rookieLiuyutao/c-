//
// Created by 95853 on 2021/9/17.
//
#include "bits/stdc++.h"

using namespace std;
typedef long long LL;
typedef unordered_map<int, int> MII;

MII u, v;
unordered_set<int > q;
int n, a, range;

int main() {
    cin >> n >> a >> range;
    while (a--) {
        
        int x, y;
        cin >> x >> y;
        u[x] = y;
    }
    while (range--) {
        int x, y;
        cin >> x >> y;
        v[x] = y;
    }
    long long res = 0;
    for (pair<int, int> x:u) {
        if (v.count(x.first)) {
            res +=(LL) (x.second * v[x.first]);
        }
    }
    cout << res;
}
