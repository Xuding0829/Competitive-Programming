#include <bits/stdc++.h>

using i64 = long long;

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

    int n;
    std::cin >> n;

    DSU dsu(n + 1);
    std::vector<edge> adj;
    for (int i = 1, w; i <= n; i++)
    {
        std::cin >> w;
        adj.push_back({0, i, w});
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1, w; j <= n; j++)
        {
            std::cin >> w;
            adj.push_back({i, j, w});
        }

    std::sort(adj.begin(), adj.end());

    int res = 0;
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
    std::cout << res << '\n';
    return 0;
}