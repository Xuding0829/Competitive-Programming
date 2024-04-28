#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

struct edge
{
    int u, v, w;
    bool operator<(const edge &t) const
    {
        return w < t.w;
    }
};

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

    DSU dsu(n);
    int res = 0;

    std::vector<edge> adj(m);
    for (int i = 0; i < m; i++)
    {
        int k, u, v, w;
        std::cin >> k >> u >> v >> w;
        u--, v--;
        adj[i] = {u, v, w};
        if (k == 1)
            dsu.merge(u, v), res += w;
    }

    auto kruskal = [&]()
    {
        std::sort(adj.begin(), adj.end());
        for (auto [u, v, w] : adj)
        {
            if (dsu.same(u, v))
                continue;
            else
            {
                res += w;
                dsu.merge(u, v);
            }
        }
        return res;
    };

    std::cout << kruskal() << '\n';

    return 0;
}