//
// Created by 95853 on 2021/6/25.
//

#include "iostream"

using namespace std;
const int N = 17;
int n;
int range[N];

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; ++i) {
            if (range[i]) {
                cout << i << ' ';
            }
        }
        puts("");
        return;
    }
    range[u] = false;
    dfs(u + 1);
    range[u] = true;
    dfs(u + 1);

}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}