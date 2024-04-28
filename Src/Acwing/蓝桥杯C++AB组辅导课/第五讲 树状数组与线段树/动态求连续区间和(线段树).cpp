#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int w[N];
int n, m;

struct Node
{
    int l, r;
    int sum;
} tree[N * 4];

void pushup(int u)
{
    tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    if (l == r)
        tree[u] = {l, r, w[r]}; // 叶节点
    else
    {
        tree[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r); // 分别构造左子树和右子树
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tree[u].l >= l && tree[u].r <= r)
        return tree[u].sum;

    int sum = 0;
    int mid = tree[u].l + tree[u].r >> 1;
    if (l <= mid)
        sum = query(u << 1, l, r);
    if (r > mid)
        sum += query(u << 1 | 1, l, r);

    return sum;
}

void modify(int u, int x, int v)
{
    if (tree[u].l == tree[u].r)
        tree[u].sum += v;
    else
    {
        int mid = tree[u].l + tree[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    build(1, 1, n);
    while (m--)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0)
            cout << query(1, a, b) << endl;
        else
            modify(1, a, b);
    }
    return 0;
}