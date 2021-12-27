//
// Created by 95853 on 2021/11/27.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
typedef long long LL;

int a[N];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ){
        cin >> a[i];
    }
    //原地求差分数组
    for(int i =n;i>1;i--)a[i]-=a[i-1];
    //差分数组的每个数的前缀和就是原数
    //所以改变差分数组的一个数，所有求前缀和时用到这个数的都会受到影响
    //思考差分数组的意义：表示原数组中每两个相邻数的差
    //将原数组都变成一样等价于将差分数组下标大于1的数都变为0
    //原数组每操作一次等价于在差分数组里选2个数，一个数-1，一个数+1
    //想要操作次数最少我们可以让每次选的2给数是一个数，一个负数
    //最后剩下的要么都是正数，要么都是负数，只能单调操作，相当于选择b[l] l = 1

    //求所有正数和所有负数的和
    int pos  = 0,neg = 0;

    for(int i = 2; i <=n; i++) {
        if (a[i]>0){
            pos+=a[i];
        }else{
            neg-=a[i];
        }
    }
    cout<<min(pos,neg)+ abs(pos-neg)<<endl;
    cout<<abs(pos-neg)+1<<endl;
}