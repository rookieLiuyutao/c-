//
// Created by 刘宇韬 on 2022/2/25.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
//1000个脉冲源+1000个神经源
const int N = 2005,INF = 0x3f3f3f3f;

//表示一共有 N 个神经元，S 个突触和 P 个脉冲源，输出时间刻 T
int n,s,p,T;
//一个正实数 Δt，表示时间间隔
double dt;
int h[N],e[N],D[N],ne[N],idx;
double w[N],v[N],u[N],a[N],b[N],c[N],d[N];
int r[N];
//存整个过程中神经元发脉冲的次数
int cnt[N];
//存某时刻某个神经元的内部参数
double I[1024][N/2];

static unsigned long _next = 1;

/* RAND_MAX assumed to be 32767 */
//这里要吧所给函数的next换一个变量名
int myrand(void) {
  _next = _next * 1103515245 + 12345;
  return((unsigned)(_next /65536) % 32768);
}

void add(int aa,int bb,double cc,int dd){
  e[idx] = bb;
  w[idx] = cc;
  D[idx] = dd;
  ne[idx] = h[aa];
  h[aa] = idx++;
}

int main(){
  memset(h,-1,sizeof h);
  scanf("%d%d%d%d", &n, &s, &p, &T);
  scanf("%lf", &dt);

  //保证所有的 RN 加起来等于 N
  for(int i = 0; i <n;) {
    //每行有以空格分隔的一个正整数 RN 和六个实数 v u a b c d
    //rn表示下面要输入rn个神经元
    int rn;
    scanf("%d", &rn);
    double vv,uu,aa,bb,cc,dd;
    scanf("%lf%lf%lf%lf%lf%lf", &vv, &uu, &aa, &bb, &cc, &dd);
    //按顺序每一行对应 RN 个具有相同初始状态和常量的神经元
    for(int j = 0; j <rn; j++,i++) {
      v[i] = vv,u[i] = uu,a[i] = aa,b[i] = bb,c[i] = cc,d[i] = dd;
    }
  }
  //输入接下来的 P 行，每行是一个正整数 r，按顺序每一行对应一个脉冲源的 r 参数
  for(int i = n; i <n+p; i++) {
    scanf("%d", &r[i]);
  }
  //循环数组的长度
  int mod = 0;
  //建图
  for(int i = 0; i < s; i++) {
    //其中 s 和 t 分别是入结点和出结点的编号；w 和 D 分别表示脉冲强度和传播延迟
    int ss,tt,dd;
    double ww;
    cin>>ss>>tt>>ww>>dd;
    add(ss,tt,ww,dd);
    mod = max(mod,dd+1);
  }
  for(int i = 0; i <T; i++) {
    //求出在循环数组中映射的坐标
    int t = i%mod;
    //遍历所有脉冲源
    for(int j = n; j <=n+p-1; j++) {
      //脉冲源在每个时刻以一定的概率发放一个脉冲
      if (r[j]>myrand()){
        //计算状态
        for(int k = h[j]; ~k ; k = ne[k]) {
          int x = e[k];
          //更新每个点的Ik,当前这个点会像下一个点隔D[k]时间后发送脉冲
          I[(t+D[k])%mod][x] +=w[k];
        }
      }
    }

    //枚举所有神经元
    for(int j = 0; j <n; j++) {
      double vv = v[j],uu = u[j];
      //根据公式，跟新状态
       v[j] = vv+dt*(0.04*vv*vv+5*vv+140-uu)+I[t][j];
       u[j] = uu+dt*a[j] *(b[j] *vv-uu);
      //如果满足 vk≥30，神经元会发放一个脉冲
       if (v[j]>=30){
         for(int k = h[j]; ~k ; k = ne[k]) {
           int x = e[k];
           //更新每个点的Ik,当前这个点会像下一个点隔D[k]时间后发送脉冲
           I[(t+D[k])%mod][x] +=w[k];
         }
         //统计该点发脉冲的次数
         cnt[j]++;
         //同时，vk 设为 c 并且 uk 设为 uk+d，其中 c 和 d 也是常量。
         v[j] = c[j],u[j]+=d[j];

       }
    }
    //因为是循环数组，所以用完一次一定要记得清空
    memset(I[t],0,sizeof I[t]);
  }
  double maxv = -INF,minv = INF;
  int maxc = -INF,minc = INF;
  for(int i = 0; i <n; i++) {
    minv = min(minv,v[i]);
    maxv = max(maxv,v[i]);
    minc = min(minc,cnt[i]);
    maxc = max(maxc,cnt[i]);
  }
  printf("%.3lf %.3lf\n", minv, maxv);
  printf("%d %d\n", minc, maxc);


}
