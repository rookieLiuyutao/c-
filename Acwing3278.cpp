//
// Created by 95853 on 2021/9/18.
//
#include "bits/stdc++.h"

using namespace std;
const int N = 1010;
int n, g[N][N],arr[N];
bool st[N];
int main() {
    cin >> n;
    int sum = 0, cnt = 0,e  =0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < arr[i]; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        bool flag = false;
        int t = g[i][0];
        for (int j = 1; j <arr[i]; j++) {
            if (g[i][j] <= 0) {
                t -= abs(g[i][j]);
            } else {
                if (g[i][j] > t) {
                    flag = true;
                    t = g[i][j];
                }
            }
        }
        sum-=t;
        if (flag) {
            cnt++;
            st[i] = true;
        }
    }
    for(int i = 0; i <n; i++) {
        if (st[i]&&st[(i+1)%n]&&st[(i+2)%n])e++;
    }
    for(int i = 0; i <n; i++) {
      for(int j = 0; j <arr[i]; j++) {
        cout<<g[i][j]<<' '<<;
      }
      cout<<endl;
    }
    cout<<sum<<' '<<cnt<<' '<<e<<endl;
}

