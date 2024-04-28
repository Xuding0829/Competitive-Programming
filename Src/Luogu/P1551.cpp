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

    int n, m, p;
    std::cin >> n >> m >> p;

    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        dsu.merge(x, y);
    }

    while (p--)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        std::cout << (dsu.same(x, y) ? "Yes\n" : "No\n");
    }

    return 0;
}