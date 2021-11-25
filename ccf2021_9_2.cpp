//
// Created by 95853 on 2021/11/25.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 500010;
int a[N], n;
bool st[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int ans = 0;
        memset(st, true, sizeof st);
        for (int j = 0; j < n; j++) {
            if (a[j] < 12 || a[j] == 0) {
                st[j] = false;
            }
        }
        for (int j = 0; j < n; j++) {
            cout << st[j] << ' ';
        }
        int j = 0;
        while (j<n){
            while (j<n&&!st[j])j++;
            ans++;
            while (j<n&&st[j])j++;
        }

        cout << endl;
        cnt = max(cnt, ans);
    }
    cout << cnt;
}