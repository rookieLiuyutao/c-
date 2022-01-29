#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 150010, INF = 0x3f3f3f3f;
int e[N], h[N], ne[N], dis[N], w[N], n, m, idx;
bool range[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int djs() {
    priority_queue<PII, vector<PII>, greater<PII>> heap;//语法问题
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    heap.push({0, 1});
    while (!heap.empty()) {
        PII t = heap.top();
        heap.pop();
        // cout << tp.x << ' ' << tp.y << endl;
        if (range[t.y])continue;
        range[t.y] = true;
        for (int i = h[t.y]; i!=-1; i = ne[i]) {
            int j = e[i];
            if (dis[j] > t.x + w[i]) {
                dis[j] = t.x + w[i];
                heap.push({dis[j], j});

            }
        }
    }
    return dis[n] >= INF ? -1 : dis[n];
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << djs() << endl;
    for (int i = 1; i <= n; i ++ )cout<<dis[i]<<' ';


}
