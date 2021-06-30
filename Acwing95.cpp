//
// Created by 95853 on 2021/6/28.
//

#include "cstring"
#include "algorithm"
#include "iostream"
#include "cstdlib"

using namespace std;

const int N = 6;
char g[N][N],temp[N][N];
int dx[] = {-1,0,1,0,0},dy[] = {0,1,0,-1,0};
void turn(int x, int y) {

    for(int i = 0; i <5; i++) {
      int a = x+dx[i],b = y+dy[i];
        if (a<0||a>=5||b<0||b>=5){
            continue;
        }
        g[a][b]^=1;
    }
}
int main(){
    int T;
    cin>>T;
    while (T--){
        int res = 100;
        for(int i = 0; i <5; i++) {
          cin>>g[i];
        }
        for(int op = 0; op <32; op++) {
            memcpy(temp,g,sizeof g);
            int count = 0;
            for(int i = 0; i <5; i++) {
                if (op>>0&1){
                    turn(0,i);
                    count++;
                }
            }
            for(int i = 0; i <4; i++) {
              for(int j = 0; j <5; j++) {
                  if (g[i][j]=='0'){
                      turn(i+1,j);
                      count++;
                  }
              }
            }
            bool success = true;
            for(int i = 0; i <5; i++) {
                if (g[4][i]=='0'){
                    success= false;
                    break;
                }
            }
            if (success){
                res = min(res,count);
            }
            memcpy(g,temp,sizeof g);

        }
        if (res>6){
            res = -1;
        }
        cout<<res<<endl;
    }
}