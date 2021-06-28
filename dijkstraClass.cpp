//
// Created by 95853 on 2021/6/27.
//
#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;
const int N = 10010;

int dist[N];
bool st[N];
int n;
int g[N][N];
int  dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 0; i <n-1; i++) {
      int t = -1;
      for(int j = 1; j <=n; j++) {
          if (!st[j]&&(t==-1||dist[t]>dist[j])){
              t = j;
          }
      }
      for(int j = 1; j <=n; j++) {
        dist[j]  = min(dist[j],dist[t]+g[t][j]);
      }
      st[t] = true;

    }
    if (dist[n]==0x3f)return -1;
    else return dist[n];


}

int main(){

}

