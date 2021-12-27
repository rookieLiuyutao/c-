#include "bits/stdc++.h"

//数据:
//4 1999999999
//A 1999999998
//Q 1
//A 1999999998
//Q 1

using namespace std;
const int N = 200010;
typedef long long LL;
struct Node {
    int l, r, v;
} tr[4 * N];
int m, mod;

void pushup(int u) {
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r)return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

}

/**
 *
 * @param u 当前节点的编号
 * @param x 要更新的节点的编号
 * @param v 要更新的最大值
 */
void update(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].v = v;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (x <= mid) update(u << 1, x, v);
    else update(u << 1 | 1, x, v);
    pushup(u);
}

int query(int u, int l, int r) {
    //树中节点已经全部被包含在区间中
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    int mid = (tr[u].l + tr[u].r) >> 1;
    int v = 0;
    if (l <= mid)v = query(u << 1, l, r);
    if (r > mid)v = max(query(u << 1 | 1, l, r), v);
    return v;
}


int main() {
    cin >> m >> mod;
    int n = 0, t = 0, x;
    char op;
    build(1, 1, m);
    while (m-- ) {
        cin >> op >> x;
        if (op == 'Q') {
            t = query(1, n - x + 1, n);
            cout << t << endl;
        } else {
            update(1, n + 1, ((LL)t + x) % mod);
            n++;
        }
    }
}
