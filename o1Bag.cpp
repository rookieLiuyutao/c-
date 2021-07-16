//
// Created by 95853 on 2021/6/26.
//
#include "iostream"
#include "algorithm"

using namespace std;

const int N =  1005;

int n,pass;
int dp[N],v[N],w[N];

int main(){
    cin >> n >> pass;
    for(int i= 1;i<n;i++)
        cin>>v[i]>>w[i];


    for(int i=1;i<=n;i++)
        for(int j = pass; j >= v[i]; j++)
            dp[j] = min(dp[j],dp[j-v[i]]+w[i]);

    cout<<dp[n];

}