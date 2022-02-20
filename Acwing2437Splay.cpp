//
// Created by 刘宇韬 on 2022/2/19.
//
/**
 * https://www.acwing.com/problem/content/2439/
 */
#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int N = 100010;
int n, m;
struct Node {
  //左儿子和右儿子和父节点
  //子节点下标用数组表示是为了方便除了选转操作
  int s[2], p;
  //该节点的key,value和该节点子树的长度,
  int k, v, size;
  //懒标记
  int flag;
  void init(int _v, int _p) {
    v = _v;
    p = _p;
  }
} tr[N];
int root, idx;
/**
 * 由子节点信息更新父节点信息
 * @param u 节点下标
 */
void pushup(int u) {
  tr[u].size = tr[tr[u].s[0]].size + tr[tr[u].s[1]].size + 1;
}
/**
 * 下传父节点的懒标记
 * @param u 节点下标
 */
void pushdown(int u) {
  if (tr[u].flag) {
    swap(tr[u].s[0], tr[u].s[1]);
    tr[tr[u].s[0]].flag ^= 1;
    tr[tr[u].s[1]].flag ^= 1;
    tr[u].flag = 0;
  }
}
/**
 * 树的节点的左右旋，旋转后不改变中序遍历的顺序
 * 左旋：把节点x往上转
 * @param x
 */
void rotate(int x) {
  int y = tr[x].p, z = tr[y].p;
  // k=0表示x是y的左儿子；k=1表示x是y的右儿子
  int k = tr[y].s[1] == x;
  tr[z].s[tr[z].s[1] == y] = x;
  tr[x].p = z;
  tr[y].s[k] = tr[x].s[k ^ 1];
  tr[tr[x].s[k ^ 1]].p = y;
  tr[x].s[k ^ 1] = y;
  tr[y].p = x;
  pushup(y);
  pushup(x);
}

void splay(int x, int k) {
  while (tr[x].p != k) {
    int y = tr[x].p, z = tr[y].p;
    if (z != k) {
      // 如果是折线关系  ==  x是y的右/左儿子 且 y是z的左/右儿子
      if ((tr[y].s[1] == x) != (tr[z].s[1] == y))
        //折线rotate两次x
        rotate(x);
      else
        //直线rotate 一次y一次x
        rotate(y);
    }
    rotate(x);
  }
  //如果k==0 根节点更新为x
  if (!k)
    root = x;
}

void insert(int v) {
  int u = root,p = 0;
  while (u) {
    p = u;
    u = tr[u].s[v>tr[u].v];
  }
  u = ++idx;
  if (p) tr[p].s[v>tr[p].v] = u;
  tr[u].init(v,p);
  splay(u,0);
}
/**
 * 根据某节点的索引，找到它在树中的位置
 * @param k 要找的点索引为k
 * @return 索引为k的点在树中的下标
 */
int get_k(int k) {
  int u = root;
  while (true) {
    //将懒标记下传
    pushdown(u);
    //如果左子树的长度大，就递归左子树
    if (tr[tr[u].s[0]].size >= k)
      u = tr[u].s[0];
    else if (tr[tr[u].s[0]].size + 1 == k)
      return u;
    else {
      k -= tr[tr[u].s[0]].size + 1;
      u = tr[u].s[1];
    }
  }
}
/**
 * 中序遍历
 * @param u
 */
void output(int u){
  pushdown(u);
  if (tr[u].s[0])
    output(tr[u].s[0]);
  if (tr[u].v>=1&&tr[u].v<=n) cout<<tr[u].v;
  if (tr[u].s[1])
    output(tr[u].s[1]);
}

int main() {
  cin >> n >> m;
  for (int i = 0; i <= n + 1; i++) {
    insert(i);
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    //因为哨兵要翻转的从[L,R]变为[L+1,R+1] 则要找L和R+2作为L+1的前继和R+1的后继
    l = get_k(l);
    r = get_k(r+2);
    // 左端点l转到根,右端点r转到左端点下面
    splay(l ,0), splay(r,l);
    // 只要将r的左子树[L+1,R+1]翻转
    tr[tr[r].s[0]].flag ^= 1;
  }
  output(root);
}