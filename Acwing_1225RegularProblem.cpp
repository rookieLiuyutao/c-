/**
 * @see 字符串 深搜 dfs
 * https://www.acwing.com/problem/content/1227/
 */

#include "bits/stdc++.h"
using namespace std;
unordered_map<string,int> save;
int n;
string ss;
int u;
int dfs(){
    int res = 0;
    while (u<ss.length()){
        if (ss[u]=='('){
            u++;
            res+=dfs();
            u++;
        } else if (ss[u]==')'){
            break;
        } else if (ss[u]=='|'){
            u++;
            res = max(res, dfs());
        } else{
            res++;
            u++;
        }
    }
    return res;
}

int main(){
    cin>>ss;
    cout<<dfs()<<endl;
}
