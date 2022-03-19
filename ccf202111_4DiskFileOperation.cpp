//
// Created by 刘宇韬 on 2022/3/19.
//
#include <iostream>
using namespace std;
const int N = 2e7 + 5, inf = 1e9 + 5;

struct Node
{
  int id, pre, val;
  bool lazy_id, lazy_pre, lazy_val;
  int lc, rc;
} tr[N];
int idx = 1;

#define cur tr[x]
#define lch tr[cur.lc]
#define rch tr[cur.rc]
#define mid (l + r >> 1)

void merge(int x)
{
  if (lch.id == rch.id && ~lch.id)
  {
    cur.id = lch.id;

    if (!cur.id && lch.pre == rch.pre)
      cur.pre = lch.pre;
    else
      cur.pre = -1;

    if (lch.val == rch.val)
      cur.val = lch.val;
    else
      cur.val = inf;
  }
  else
    cur.id = -1;
}
void pushdown(int x)
{
  if (!cur.lc)
    cur.lc = ++idx, cur.rc = ++idx;
  if (cur.lazy_id)
    lch.lazy_id = rch.lazy_id = 1, cur.lazy_id = 0,
            lch.id = rch.id = cur.id;
  if (cur.lazy_pre)
    lch.lazy_pre = rch.lazy_pre = 1, cur.lazy_pre = 0,
            lch.pre = rch.pre = cur.pre;
  if (cur.lazy_val)
    lch.lazy_val = rch.lazy_val = 1, cur.lazy_val = 0,
            lch.val = rch.val = cur.val;
}

int L, R;
int find(int x, int l, int r, int id)
{
  if (~cur.id)
    return cur.id == id || !cur.id ? min(R, r) : -1;
  pushdown(x);
  if (mid < L)
    return find(cur.rc, mid + 1, r, id);
  if (mid < R)
  {
    int res = find(cur.lc, l, mid, id);
    if (res == mid)
      return max(res, find(cur.rc, mid + 1, r, id));
    return res;
  }
  return find(cur.lc, l, mid, id);
}
void modify(int x, int l, int r, int id, int val)
{
  if (l >= L && r <= R)
    cur.id = id, cur.val = val, cur.lazy_id = cur.lazy_val = 1;
  else
  {
    pushdown(x);
    if (mid >= L)
      modify(cur.lc, l, mid, id, val);
    if (mid < R)
      modify(cur.rc, mid + 1, r, id, val);
    merge(x);
  }
}

bool check(int x, int l, int r, int id, bool op)
{
  if (~cur.id && (!op || ~cur.pre))
    return op ? !cur.id && cur.pre == id : cur.id == id;
  pushdown(x);
  if (mid >= L && !check(cur.lc, l, mid, id, op))
    return false;
  if (mid < R && !check(cur.rc, mid + 1, r, id, op))
    return false;
  return true;
}
void erase(int x, int l, int r)
{
  if (l >= L && r <= R)
    cur.pre = cur.id, cur.id = 0, cur.lazy_pre = cur.lazy_id = 1;
  else
  {
    pushdown(x);
    if (mid >= L)
      erase(cur.lc, l, mid);
    if (mid < R)
      erase(cur.rc, mid + 1, r);
    merge(x);
  }
}
void restore(int x, int l, int r)
{
  if (l >= L && r <= R)
    cur.id = cur.pre, cur.lazy_id = 1;
  else
  {
    pushdown(x);
    if (mid >= L)
      restore(cur.lc, l, mid);
    if (mid < R)
      restore(cur.rc, mid + 1, r);
    merge(x);
  }
}

void query(int x, int l, int r, int pos)
{
  if (~cur.id && cur.val != inf)
    printf("%d %d\n", cur.id, cur.id ? cur.val : 0);
  else
  {
    pushdown(x);
    if (mid >= pos)
      query(cur.lc, l, mid, pos);
    else
      query(cur.rc, mid + 1, r, pos);
  }
}

int n, m, k;
int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for (int op, id, x; k--;)
  {
    scanf("%d", &op);
    if (op == 0)
    {
      scanf("%d%d%d%d", &id, &L, &R, &x);
      R = find(1, 1, m, id), printf("%d\n", R);
      if (~R)
        modify(1, 1, m, id, x);
    }
    else if (op == 1)
    {
      scanf("%d%d%d", &id, &L, &R);
      if (check(1, 1, m, id, 0))
        erase(1, 1, m), printf("OK\n");
      else
        printf("FAIL\n");
    }
    else if (op == 2)
    {
      scanf("%d%d%d", &id, &L, &R);
      if (check(1, 1, m, id, 1))
        restore(1, 1, m), printf("OK\n");
      else
        printf("FAIL\n");
    }
    else
      scanf("%d", &x), query(1, 1, m, x);
  }
}