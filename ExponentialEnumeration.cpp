//
// Created by 95853 on 2021/6/25.
//

#include "iostream"

using namespace std;
const int N = 17;
int n;
int st[N];

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; ++i) {
            if (st[i]) {
                cout << i << ' ';
            }
        }
        puts("");
        return;
    }
    st[u] = false;
    dfs(u + 1);
    st[u] = true;
    dfs(u + 1);

}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}