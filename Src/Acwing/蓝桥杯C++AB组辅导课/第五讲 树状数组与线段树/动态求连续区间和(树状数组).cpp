#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N], tree[N];
int n, m;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int y)
{
    for (int i = x; i <= n; i += lowbit(i))
        tree[i] += y;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        res += tree[i];
    return res;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        add(i, a[i]);

    while (m--)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if (!k)
            cout << query(y) - query(x - 1) << endl;
        else
            add(x, y);
    }
    return 0;
}