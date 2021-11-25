
#include "bits/stdc++.h"

using namespace std;
const int N = 1010;
int n;
typedef pair<int, int> PII;
int ans[5];
int dx[8] = {0, 1, 0, -1, -1, 1, 1, -1}, dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};
PII h[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i].first >> h[i].second;
    }
    for (int i = 0; i < n; i++) {
        bool s[4] = {false};
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int x = h[i].first + dx[k], y = h[i].second + dy[k];
                if (x == h[j].first && y == h[j].second){
                    s[k] = true;
                }
            }
            for(int k = 4; k <8; k++) {
                int x = h[i].first + dx[k], y = h[i].second + dy[k];
                if (x == h[j].first && y == h[j].second){
                    cnt++;
                }
            }
        }
        if (s[0]&&s[1]&&s[2]&&s[3]){
            ans[cnt]++;
        }

    }
    for (int an : ans) {
        cout << an << endl;
    }
}


