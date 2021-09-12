//
// Created by 95853 on 2021/8/16.
//
#include "iostream"
using namespace std;
const int N = 1010;
int g[N][N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i <n; i++) {
      for(int j = 0; j <m; j++) {
        cin>>g[i][j];
      }
    }
    for(int i = m-1; i >=0; i--) {
      for(int j = 0; j <n; j++) {
        cout<<g[j][i]<<' ';
      }
      cout<<endl;
    }
}
