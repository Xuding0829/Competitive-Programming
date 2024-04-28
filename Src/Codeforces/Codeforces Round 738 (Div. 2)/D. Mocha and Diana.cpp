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

    int n, m1, m2;
    std::cin >> n >> m1 >> m2;

    DSU dsu1(n), dsu2(n);
    while (m1--)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        dsu1.merge(u, v);
    }

    while (m2--)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        dsu2.merge(u, v);
    }

    std::vector<std::pair<int, int>> res;
    for (int i = 1; i < n; i++)
    {
        if (!dsu1.same(0, i) && !dsu2.same(0, i))
        {
            res.push_back({0, i});
            dsu1.merge(0, i);
            dsu2.merge(0, i);
        }
    }

    std::vector<int> a, b;
    for (int i = 1; i < n; i++)
    {
        if (dsu1.leader(i) == i && !dsu1.same(0, i))
            a.push_back(i), dsu1.merge(0, i);
        if (dsu2.leader(i) == i && !dsu2.same(0, i))
            b.push_back(i), dsu2.merge(0, i);
    }

    for (int i = 0; i < std::min(a.size(), b.size()); i++)
        res.push_back({a[i], b[i]});

    std::cout << res.size() << '\n';
    for (auto [u, v] : res)
        std::cout << u + 1 << ' ' << v + 1 << '\n';
        
    return 0;
}