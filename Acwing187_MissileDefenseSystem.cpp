//
// Created by 95853 on 2021/7/14.
//

#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n,res,arr[N],up[N],down[N];
 void dfs(int u,int sUp,int sDown){
     //剪枝
     //res保存了之前搜索过的最小值
     //如果当前这一枝结果更大，就可以剪掉
    if (sUp+sDown>=res){
        return;
    }
    //搜索结束，退出
    if (u==n){
        res = sUp+sDown;
        return;
    }
    //贪心思路搜上升子序列
    //将当前的数接在up中能接的最小位置
    int k = 0;
    while (k<sUp&&up[k]>=arr[u]){
        k++;
    }
    int t = up[u];
    up[k] = arr[u];
    if(k<sUp){
        dfs(u+1,sUp,sDown);
    }else {
        dfs(u+1,sUp+1,sDown);
    }
    up[k] = t;

    k = 0;
    while (k<sDown&&down[k]<=arr[u]){
        k++;
    }
    t = down[k];
    down[k] = arr[u];
    if (k<sDown){
        dfs(u+1,sUp,sDown);
    }else {
        dfs(u+1,sUp,sDown+1);
    }
    down[k] = t;

}

int main(){
    while (cin>>n,n){
        for(int i = 0; i <n; i++) {
          cin>>arr[i];
        }
        //将res初始化为一个最大值
        res =n;
        dfs(0,0,0);

        cout<<res<<endl;

    }

 }

