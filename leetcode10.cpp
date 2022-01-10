//
// Created by 95853 on 2021/6/26.
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    s = ' ' + s;
    p = ' ' + p;
//    bool dp[n + 1][pass + 1];
    vector<vector<bool>> dp(n+1,vector<bool>(m+1));
    dp[0][0] = true;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j + 1 <= m && p[j + 1] == '*')continue;
            if (i && p[j] != '*') {
                dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
            } else if (p[j] == '*') {
                dp[i][j] = dp[i][j - 2] || i && dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
            }
        }
    }
    return dp[n][m];
}

int main() {
    string s = "mississippi";
    string p = "mis*is*phone*.";
    cout <<isMatch(s,p);

}