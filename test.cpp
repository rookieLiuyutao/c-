#include <iostream>
#include <cstring>
#include <algorithm>
#include "vector"
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second

const int N = 100010;
PII mes[N];
int n,d,k;
vector <int >ans;
int main()
{
    cin >> n>>d>>k;

    for (int i = 0; i < n; i ++ )cin>>mes[i].y>>mes[i].x;
    sort(mes,mes+n);
     for (int i = 0; i < n; i ++ )cout<<mes[i].x<<' '<<mes[i].y<<endl;
    for (int i = 0; i < n; i ++ ){
        int j = i;
        int cnt = 0;
        while(j<n&&mes[j].x==mes[i].x){
            if(mes[j].y-mes[i].y<d){
                cnt++;
                if(cnt>=k){
                    ans.push_back(mes[i].x);
                }else{
                    cnt=0;
                }
            }
            j++;
        }

        i = j;
    }
    for(int x:ans)cout<<x<<endl;
}