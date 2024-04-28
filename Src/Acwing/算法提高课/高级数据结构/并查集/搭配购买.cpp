#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

using i64 = long long;

struct DSU
{
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1)
    {
        std::iota(f.begin(), f.end(), 0);
    }
    int leader(int x)
    {
        return x == f[x] ? x : f[x] = leader(f[x]);
    }
    bool same(int x, int y)
    {
        return leader(x) == leader(y);
    }
    void merge(int x, int y)
    {
        x = leader(x), y = leader(y);
        if (x != y)
        {
            siz[x] += siz[y];
            f[y] = x;
        }
    }
    int size(int x)
    {
        return siz[leader(x)];
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, m;
    std::cin >> n >> k >> m;

    std::vector<int> v(n), w(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i] >> w[i];

    DSU dsu(n);
    while (k--)
    {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        dsu.merge(a, b);
    }

    for (int i = 0; i < n; i++)
    {
        int fa = dsu.leader(i);
        if (fa == i)
            continue;
        v[fa] += v[i], w[fa] += w[i];
    }

    std::vector<int> f(m + 1);
    for (int i = 0; i < n; i++)
        if (dsu.leader(i) == i)
            for (int j = m; j >= v[i]; j--)
                f[j] = std::max(f[j], f[j - v[i]] + w[i]);
    std::cout << f[m] << '\n';
    return 0;
}