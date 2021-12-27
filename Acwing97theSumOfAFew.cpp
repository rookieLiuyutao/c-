//
// Created by 95853 on 2021/11/26.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

const int mod = 9901;
unordered_map<int, int> pr;

int a, b;

/**
 * 对n分解质因数
 * @param n
 */
void devide(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                pr[i]++;
                n /= i;
            }
        }
    }
    if (n > 1)pr[n]++;
}

/**
 * 快速幂
 * @param x
 * @param y
 * @param p
 * @return
 */
int qmi(int x, int y, int p) {
    int res = 1 % p;
    while (y) {
        if (y & 1) res = (LL) res * x % p;
        x = (LL) x * x % p;
        y >>= 1;
    }
    return res;
}
/**
 * 分治求 p0+p1+…+pk−1
 * @param p
 * @param k
 * @return
 */
int sum(int p, int k) {
    if (k == 1)return 1;
    if (k & 1)return (qmi(p, k - 1, mod) + sum(p, k - 1)) % mod;
    return (LL) (qmi(p, k / 2, mod) + 1) * sum(p, k / 2) % mod;

}

int main() {
    cin >> a >> b;
    devide(a);
    int res = 1;
    for (auto i:pr) {
        int x = i.first, y = i.second*b;
        res = (LL) res * sum(x,y+1)%mod;
    }
    if(a==0)res = 0;
    cout<<res;
}
