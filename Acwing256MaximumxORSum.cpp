#include "bits/stdc++.h"

/**
 * 题目要求支持2种操作：
 * 1:向序列末尾添加一个数
 * 2：查询每个[l,r]区间内找一个数p，使[p^...N^x]的值最大，N为当下序列的长度
 * 思路：看到[连续的数的异或]就应该想到前缀树+前缀和,但时间复杂度为n2
 * 优化：如果每插一个数都存下当前从[1...N]中，满足条件的最大值需要nlogn,这种能存下每个历史版本的trie树就是[可持久化trie树]
 * 完善：以上思路只能解决区间在[1,r]时，题目要求[l,r]。所以想到了每个节点存1个[满足条件的所有p中下标最大的那个下标，且这个下标必须大于等于l]
 */

using namespace std;
const int N = 600010, M = N * 25;
int n, m;
//注意,这里要开M,因为每个数的范围是10e7，大约是24位二进制数
int tr[M][2];
//用来存前缀异或和
int q[N];
//存每个数的根节点编号
int root[N];
//节点编号
int idx;

int max_id[M];
/**
 * 每插进来一个新的数，相当于加入一条路径
 * @param i 前缀和数组的下标
 * @param p 上个版本根节点的下标
 * @param q 当前版本根节点的下标
 * @param k 当前处理到了二进制位的第几位(因为要用递归的写法，所以要传这个参数)
 */
void insert(int i, int p, int q) {
    max_id[q] = i;
    for(int k = 23; k >=0; k--) {
        int v = q[i] >> k & 1;
        //如果新的路径走了已经存在的节点，就复制原来的信息
        if (p) {
            tr[q][v ^ 1] = tr[p][v ^ 1];
        }
        //否则就开一个新的点
        tr[q][v] = ++idx;
        max_id[tr[q][v]] = i;
        q = tr[q][v], p = tr[p][v];
    }
}

int query(int first, int p, int l) {
    int q = first;
    for (int i = 23; i >= 0; i--) {
        int v = p >> i & 1;
        int b = tr[q][v ^ 1];
        if (b && max_id[b] >= l) {
            q = tr[q][v ^ 1];
        } else {
            q = tr[q][v];
        }
    }
    return q[max_id[q]] ^ p;
}

int main() {
    cin >> n >> m;
    max_id[0] = -1;
    root[0] = ++idx;
    insert(0, 0, root[0]);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        q[i] = q[i - 1] ^ a;
        root[i] = ++idx;
        insert(i, root[i - 1], root[i]);

    }
    char op;
    int l, r, x;
    while (m--) {

        cin >> op;
        if (op == 'Q') {
            cin >> l >> r >> x;
            cout << query(root[r - 1], q[n] ^ x, l - 1) << endl;
        } else {
            cin >> x;
            root[++n] = ++idx;
            q[n] = q[n - 1] ^ x;
            insert(n, root[n - 1], root[n]);
        }
    }
}



