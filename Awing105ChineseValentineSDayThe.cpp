//
// Created by 95853 on 2022/1/28.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;

int row[N],col[N],s[N],c[N];
LL work(int n,int a[]){

  for(int i = 1;i<=n;i++)s[i] = s[i-1]+a[i];
  if(s[n]%n) return -1;
  int avg = s[n]/n;
  c[1] = 0;
  LL res = 0;
  for(int i = 2;i<=n;i++){
    c[i] = s[i-1]-(i-1)*avg;
  }
  sort(c+1,c+n+1);
  for(int i =1;i<=n;i++)res+=abs(c[i]-c[(n+1)/2]);
  return res;
}

int main(){
  int n,m,cnt;
  cin>>n>>m>>cnt;
  while (cnt--){
    int x,y;
    cin>>x>>y;
    row[x]++;
    col[y]++;
  }
  LL rr = work(n,row);
  LL cc = work(m,col);
  if(rr!=-1&&cc!=-1){
    cout<<"both "<<rr+cc<<endl;
  }else if(rr!=-1){
    cout << "row "<<rr<<endl;
  }else if(cc!=-1){
    cout << "column "<<cc<<endl;
  }else{
    cout << "impossible"<<endl;
  }
}