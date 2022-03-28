/**
 * @author 大菜狗
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define pb push_back
#define fi first
#define se second

const int N = 100010;
int mp[N];
int n,k;

LL get(int a,int b){
  LL res = 1;
  while (b--){
    res*=a;
    if (res>=N) res = 0;
  }
  return res;
}

int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>k;
  int res = 0;
  while (n--){
    int x;
    cin>>x;
    LL y = 1,z = 1;
    for(int i = 2; i <=x/i; i++) {
      if (x%i==0){
        int cnt = 0;
        while (x%i==0) x/=i,cnt++;
        cnt%=k;
        if(cnt){
          y*= get(i,cnt);
          z*= get(i,k-cnt);
        }
      }
    }
    if (x>1){
      y*= x;
      z*= get(x,k-1);
    }
    if(z>=N) z = 0;
    res+=mp[z];
    mp[y]++;
  }
  cout<<res;
}