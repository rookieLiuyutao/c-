/*
 * https://www.acwing.com/problem/content/255/
 */
#include "bits/stdc++.h"
using namespace std;
const int N = 100010, INF = 1e8;
// root表示根节点，idx表示全局节点的编号
int n, root, idx;
struct Node {
  //表示左儿子和右儿子
  int l, r;
  // k表示二叉搜索树的权值，v表示堆的权值
  int k, v;
  // cnt和size是为了记录排名设置的:
  // cnt表示该值出现的次数，size表示该节点子树的个数
  int cnt, size;
} tr[N];

void pushup(int p) {
  tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}
/**
 * 创建一个节点
 * @param k
 * @return
 */
int get_node(int k) {
  tr[++idx].k = k;
  tr[idx].v = rand();
  //每次新创建的点都是叶子节点，所以cnt和size都为1
  tr[idx].cnt = tr[idx].size = 1;
  return idx;
}

void build() {
  //创建两个哨兵
  get_node(-INF);
  get_node(INF);
  root = 1;
  tr[1].r = 2;
  pushup(root);
}

/**
 * 右旋
 * @param p
 */
void zig(int &p) {
  int q = tr[p].l;
  tr[p].l = tr[q].r;
  tr[q].r = p;
  p = q;
  pushup(tr[p].l);
  pushup(p);
}
/**
 * 左旋
 * @param p
 */
void zag(int &p) {
  int q = tr[p].r;
  tr[p].r = tr[q].l;
}

void insert(int &p,int k){

}

int main() {
  cin >> n;
  int op, x;
  while (n--) {
    cin >> op >> x;
    if (op == 1)
      insert(root, x);
    else if (op == 2)
      remove(root, x);
    else if (op == 3)
      cout << grbk(root, x);
    else if (op == 4)
      cout << gkbr(root, x);
    else if (op == 5)
      cout << get_prev(root, x);
    else
      cout << get_next(root, x);
  }
}
