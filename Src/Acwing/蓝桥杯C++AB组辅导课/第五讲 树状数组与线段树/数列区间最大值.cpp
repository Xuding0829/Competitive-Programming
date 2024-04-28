#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m;

struct Node
{
    int l, r;
    int maxv;
} tr[N * 4];

void pushup(int u)
{
    tr[u].maxv = max(tr[u << 1].maxv, tr[u << 1 | 1].maxv);
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, a[r]};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].maxv;
    int mid = tr[u].l + tr[u].r >> 1;
    int res = INT_MIN;
    if (l <= mid)
        res = query(u << 1, l, r);
    if (r > mid)
        res = max(res, query(u << 1 | 1, l, r));
    return res;
}

signed main()
{
    scanf("%d%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    build(1, 1, n);

    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, l, r));
    }

    return 0;
}