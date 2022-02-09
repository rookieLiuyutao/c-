//
// Created by 刘宇韬 on 2022/2/4.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 10010;
int p[N];
int s[N];
int find(int x){
  if (x!=p[x])p[x] = find(p[x]);
  return p[x];
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i = 1; i <=n; i++) {
    p[i] = i;
    //存储当前点所在连通块的点的数量
    s[i] = 1;
  }
  while (m--){
    string op;
    cin>>op;
    if (op=="C"){
      int a,b;
      cin>>a>>b;
      int pa = find(a) ,pb = find(b);
      if (pa==pb) continue;
      p[pa] = pb;
      s[b]+=s[a];

    }else if (op=="Q1"){
      int a,b;
      cin>>a>>b;
      if (find(a)== find(b)){
        puts("Yes");
      }else{
        puts("No");
      }
    }else if (op=="Q2"){
      int a;
      cin>>a;
      cout<<s[a]<<endl;
    }
  }

}    