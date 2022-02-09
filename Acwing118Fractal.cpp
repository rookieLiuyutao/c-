//
// Created by 刘宇韬 on 2022/2/3.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 1010;
bool g[N][N];
void dfs(int n,int x,int y){
  if (n==1){
    g[x][y] = true;
    return;
  }
  int len = 1;
  for(int i = 0; i <n-2; i++) {
    len*=3;
  }
  dfs(n-1,x,y);
  dfs(n-1,len*2+x,y);
  dfs(n-1,x,len*2+y);
  dfs(n-1,len*2+x,len*2+y);
  dfs(n-1,x+len,y+len);

}


int main(){
  int n;
  while(cin>>n,n!=-1){
    memset(g, false,sizeof g);
    dfs(n,1,1);
    int m = 1;
    for(int i = 0; i <n-1; i++) {
      m*=3;
    }
    for(int i = 1; i <=m; i++) {
      for(int j = 1; j <=m; j++) {
        if (g[i][j])cout<<"X";
        else cout<<" ";
      }
      puts("");
    }
    puts("-");
  }
}