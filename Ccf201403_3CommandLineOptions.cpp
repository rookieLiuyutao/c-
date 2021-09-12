//
// Created by 95853 on 2021/8/14.
//
#include "bits/stdc++.h"

using namespace std;

int main() {
    string ss;
    cin >> ss;
    unordered_map<char, char> p;
    for (int i = 0; i < ss.size(); i++) {
        if (i != ss.size() - 1 && ss[i + 1] == ':') {
            p[ss[i]] = ':';
            i++;
        } else {
            p[ss[i]] = '*';
        }
    }
    for (auto m:p)cout << m.first << " " << m.second << endl;
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i <= n; i++) {
        map<string, string> q;
        string str;
        getline(cin, str);
        stringstream ssin(str);
        vector<string> op;
        while (ssin >> str)op.push_back(str);
        for (int j = 1; j < op.size(); j++) {
            if (op[j][0] != '-' || op[j][1] < 'a' || op[j].size() != 2)break;
            if (j + 1 < op.size() && p.count(op[j][1]) && p[op[j][1]] == ':') {
                q[string(1, op[j][1])] = op[j + 1];
                i++;
            } else if (p.count(op[j][1]) && p[op[j][1]] != ':') {
                q[string(1, op[j][1])] = '!';
            } else {
                break;
            }
        }
        string res = "";
        for (auto m:q) {
            if (m.second != "!") {
                res.append("-").append(m.first).append(" ").append(m.second).append(" ");
            } else {
                res.append("-").append(m.first).append(" ");
            }
        }
        for (auto m:q)cout << m.first << " " << m.second << endl;
        cout << "Case " << i << ": " << res << endl;
    }


}
