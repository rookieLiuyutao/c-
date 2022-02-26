//
// Created by 刘宇韬 on 2022/2/23.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int q[N];
int n;
void qs(int l,int r){
  if(l>=r) return;
  int x = q[l+r>>1],i = l-1,j = r+1;
  while(i<j){
    do i++; while(q[i]<x);
    do j--; while(q[j]>x);
    if(i<j)swap(q[i],q[j]);

  }
  qs(l,j);
  qs(j+1,r);
}
int main(){
  cin>>n;
  for(int i = 0;i<n;i++)cin>>q[i];
  qs(0,n-1);
  for(int i = 0;i<n;i++)cout<<q[i]<<' ';
}