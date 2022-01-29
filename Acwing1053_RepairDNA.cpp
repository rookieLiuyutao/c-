/**
 * http://poj.org/problem?id=3691
 */
#include <cstdio>
#include <cstring>
#include "string"
#include "iostream"
#include <algorithm>

using namespace std;
const int N = 1010;
int ne[N], tr[N][4], idx, q[N], n, range[N], dp[N][N],get_num[128];


void insert(string str) {
    int p = 0;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        int t = get_num[str[i]];
        if (!tr[p][t]) {
            tr[p][t] = ++idx;
        }
        p = tr[p][t];
    }
    range[p] = 1;
}

void build() {
    int hh = 0, tt = -1;
    for (int i = 0; i < 4; i++) {
        if (tr[0][i])q[++tt] = tr[0][i];
    }
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = 0; i < 4; i++) {
            int p = tr[t][i];
            if (!p)tr[t][i] = tr[ne[t]][i];
            else {
                ne[p] = tr[ne[t]][i];
                q[++tt] = p;
                range[p] |= range[ne[p]];
            }
        }
    }
}

int main() {
    get_num['A'] = 0, get_num['T'] = 1, get_num['G'] = 2, get_num['C'] = 3;
    int T = 1;
    while (cin >> n, n) {
        memset(tr, 0, sizeof tr);
        memset(ne, 0, sizeof ne);
        memset(range, 0, sizeof range);
        idx = 0;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            insert(str);
        }
        string text;
        cin >> text;
        build();
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        int m = text.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= idx; j++) {
                for (int k = 0; k < 4; k++) {
                    int flag = get_num[text[i + 1]] != k;
                    int p = tr[j][k];
                    if (!range[p]) {
                        dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + flag);
                    }
                }
            }
        }
        int res = 0x3f3f;
        for(int i = 0; i <=idx; i++) {
          res = min(res,dp[m][i]);
        }
        if (res ==0x3f3f){
            res = -1;
        }
        printf("Case %d: %d\n",T++,res);
    }
}

