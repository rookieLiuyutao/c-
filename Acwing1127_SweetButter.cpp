/**
 * http://ybt.ssoier.cn:8088/problem_show.php?pid=1345
 */
#include "bits/stdc++.h"

using namespace std;
const int N = 1500,INF = 0x3f3f3f3f;
int h[N], e[N], ne[N], w[N], dis[N], arr[N], n, m, phone, idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(int start) {
    queue<int> q;
    memset(dis, 0x3f, sizeof dis);
    dis[start] = 0;
    q.push(start);
    st[start] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dis[j] > dis[t] + w[i]) {
                dis[j] = dis[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    int res = 0;
    for(int i = 1; i <=n; i++) {
        if (dis[arr[i]]==INF)return INF;
        else res+=dis[arr[i]];

    }
    return res;
}

int main() {
    cin >> n >> phone >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(h,-1,sizeof h);
    while (m--) {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    int ans = INF;
    for(int i = 1; i <= phone; i++) {
       ans =  min(ans, spfa(i));
    }
    cout<<ans;
}