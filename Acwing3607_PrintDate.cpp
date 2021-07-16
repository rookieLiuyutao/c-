//
// Created by 95853 on 2021/7/14.
//

#include "bits/stdc++.h"

using namespace std;
int n, pass;

int main() {
    unordered_map<int, int> map = {
            {1,  31},
            {2,  28},
            {3,  31},
            {4,  30},
            {5,  31},
            {6,  30},
            {7,  31},
            {8,  31},
            {9,  30},
            {10, 31},
            {11, 30},
            {12, 31}
    };
    while (cin >> n >> pass) {
        if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) {
            map[2] = 29;
        }else{
            map[2]= 28;
        }
        int month  =1,day = 1;
        for(int i = 1; i <=12; i++) {
            if (pass>=map[i]){
                pass-=map[i];
            } else{
                month = i;
                day = pass;
                break;
            }

        }
        printf("%04d-%02d-%02d\n",n,month,day);

    }
}