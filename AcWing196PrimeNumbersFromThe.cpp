//
// Created by 95853 on 2022/1/22.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef long long LL;
int p[N],cnt;
bool range[N];
void init(int n){
  memset(range,0,sizeof range);
  for(int i =2;i<=n;i++){
        if(!range[i])p[cnt++] = i;
        for(int j = 0;j<p[j]*i;j++){
          range[p[j]*i] = true;
            if(i%p[j]==0)break;
        }
    }
}
int main(){
    int l,r;
    while(cin>>l>>r){
        init(50000);
        memset(range,0,sizeof range);
        //枚举所有质数，找到在[l,r]中中这些质数的倍数
        for(int i = 0;i<cnt;i++){
            LL u = p[i];
            //找到大于等于l的u的最小倍数，这个倍数一定要大于2倍，因为筛法是从2倍开始筛的
            //(l+u-1)/u是l/u上取整
            for(LL j = max(u*2,(l+u-1)/u*u);j<=r;j+=u){
                //下标用偏移量存
                range[j-l] = true;
            }
        }
        //复用p数组，将[l,r]的所有倍数存在p数组中，同筛法一样，也是从2倍开始
        cnt = 0;
        for(int i = 0;i<=r-l;i++){
            if(!range[i]&&i+l>=2){
                p[cnt++] = i+l;
            }
        }
        if(cnt<2)puts("There are no adjacent primes.");
        else{
            //遍历所有相邻的质数，找到最大和最小差
            int minp = 0,maxp = 0;
            for(int i = 0;i+1<cnt;i++){
                int d = p[i+1]-p[i];
                if(d<p[minp+1]-p[minp-1] )minp = i;
                if(d>p[maxp+1]-p[maxp-1])maxp = i;
            }
          printf("%d,%d are closest, %d,%d are most distant.\n",
                 p[minp], p[minp + 1],
                 p[maxp], p[maxp + 1]);
        }
    }
}