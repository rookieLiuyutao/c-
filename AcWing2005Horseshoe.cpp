
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 7;
bool g[N][N] , range[N][N];
int n,m;
int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
int ans;
void dfs(int x,int y,int cl,int cr){
  if (cl==cr)ans = max(cl+cr,ans);

  for(int i = 0; i <4; i++) {
    int a = x+dx[i],b = y+dy[i];
    if (a<0||a>=n||b<0||b>=n || range[a][b])continue;
    if (g[x][y]&&!g[a][b])continue;
    range[x][y] = true;
    if (g[a][b])
      dfs(a,b,cl,cr+1);
    else
      dfs(a,b,cr+1,cl);
    range[x][y] = false;
  }
}

int main(){
  cin>>n;
  char c;
  for(int i = 0; i <n; i++) {
    for(int j = 0; j <n; j++) {
      cin>>c;
      g[i][j] = (c==')');
    }
  }
  int res = 0;
  if (!g[0][0]){
    dfs(0,0,1,0);
    res = ans;
  }
  cout<<res;


}