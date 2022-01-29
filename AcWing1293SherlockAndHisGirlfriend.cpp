//
// Created by 95853 on 2022/1/22.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int p[N],cnt;
bool range[N];
void init(int n){
  for(int i = 2;i<=n;i++){
    if(!range[i]) p[cnt++] =  i;
    for(int j = 0;p[j]*i<=n;j++){
      range[p[j]*i] = true;
      if(i*p[j]==0) break;
    }
  }
}
int main(){
  int n;
  cin>>n;
  init(n+1);
  if(n<=2)cout<<1<<endl;
  else cout<<2<<endl;

  for(int i = 2;i<=n+1;i++){
    if(!range[i])cout<<1<<' ';
    else cout<<2<<' ';
  }
}