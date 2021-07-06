/**
 * @see 深搜 字符串 https://www.acwing.com/problem/content/3486/
 */
#include "bits/stdc++.h"
using namespace std;

string dfs(int n){
    string res;
    for(int i = 29; i >=0; i--) {
        if ((n>>i&1)==1){
            if (!res.empty()){
                res+="+";
            }
            string temp;
            if (i==0){
                res+="2(0)";
            } else if (i==1){
                res+="2";
            } else{
                temp="2("+dfs(i)+")";
            }
            res+=temp;
        }
    }
    return res;
}

int main(){
    int n;
    while (cin>>n){
        cout<<dfs(n)<<endl;
    }


}