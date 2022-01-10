#include "bits/stdc++.h"
using namespace std;
vector<string> source;
vector<string > up,down;
int n;
int main(){
  string x;
  cin>>n;
  for(int i = 0; i <n; i++) {
    cin>>x;
    source.push_back(x);
    string t1,t2;
    sort(x.begin(),x.end());
    t1 = x;
    for(int j = x.size()-1; j >=0; j--) {
      t2+=x[j];
    }
    up.push_back(t1);
    down.push_back(t2);

  }
  sort(up.begin(),up.end());
  sort(down.begin(),down.end());
  for(auto x:up)cout<<x<<' ';
  cout<<endl;
  for(auto x:down)cout<<x<<' ';
  for(int i = 0; i <n; i++) {
    int l = 0,r = n-1;
    string x = source[i];
    sort(x.begin(),x.end());
    while (l<r){
      int mid = (l+r)>>1;
      if (source[i]<=down[mid]){
        r = mid;
      }else{
        l = mid+1;
      }
    }
    cout<<l+1<<' ';
    reverse(x.begin(),x.end());
    l = 0,r = n-1;
    while (l<r){
      int mid = (l+r+1)>>1;
      if (source[i]>=up[mid]){
        l = mid;
      }else{
        r = mid-1;
      }
    }
    cout<<r+1<<endl;

  }

}
