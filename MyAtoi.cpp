//
// Created by 95853 on 2021/6/26.
//
#include "iostream"
#include "cstring"
#include "cstdlib"

using namespace std;

int myAtoi(string s) {
    int n = s.length();
    int k = 0;
    while (k<n&&s[k]==' ')k++;
    while (k==n)return 0;
    int sign = 1;
    if (s[k]=='-'){
        sign=-1;
        k++;

    } else if (k=='+')k++;
    long long res = 0;
    while (k<n&&s[k]>='0'&&s[k]<='9'){
        res = res*10+s[k]-'0';
        k++;
        if (res>INT_MAX) return INT_MAX;
    }
    res*=sign;
    if (res>INT_MAX)return INT_MAX;
    if (res<INT_MIN)return INT_MIN;

    return res;

}
int main(){
    string s = "   -42";
    cout<<myAtoi(s)<<endl;
    cout<<s[3];
}