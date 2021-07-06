
/**
 * @see 线性dp 最长上升子序列
 * https://www.luogu.com.cn/problem/P2782
 */

#include "bits/stdc++.h"

using namespace std;

const int N = 1010;
int arr[N], save[N],  n;

pair<int ,int >city[N];

int main() {
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> city[i].first>> city[i].second;
    }
    sort(city,city+n);

    for (int i = 0; i < n; i++) {
        int l = 0, r = res;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (save[mid] < city[i].second) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        save[l + 1] = city[i].second;
        res = max(res, l + 1);
    }
    cout<<res<<endl;

}