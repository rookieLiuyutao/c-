//
// Created by 95853 on 2021/8/2.
//

#include "bits/stdc++.h"

using namespace std;
unordered_map<int, int> save;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        save[x]++;
    }
    int res = 0, temp = INT_MAX;
    for (auto[x, y]:save) {
        if (y > res || (y == res && x < temp)) {
            res = y;
            temp = x;
        }
    }
    cout << temp;

}