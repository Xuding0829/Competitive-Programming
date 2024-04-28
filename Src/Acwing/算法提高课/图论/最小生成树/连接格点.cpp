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

    int n, m;
    std::cin >> n >> m;

    DSU dsu(n * m + 1);

    int x1, y1, x2, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2)
    {
        int u = (x1 - 1) * m + y1;
        int v = (x2 - 1) * m + y2;
        dsu.merge(u, v);
    }

    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int u = (j - 1) * m + i;
            int v = j * m + i;
            if (dsu.same(u, v))
                continue;
            else
                res++, dsu.merge(u, v);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int u = (i - 1) * m + j;
            int v = (i - 1) * m + j + 1;
            if (dsu.same(u, v))
                continue;
            else
                res += 2, dsu.merge(u, v);
        }
    }

    std::cout << res << '\n';
    return 0;
}