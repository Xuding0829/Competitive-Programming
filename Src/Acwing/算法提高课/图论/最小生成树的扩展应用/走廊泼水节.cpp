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

void solve()
{
    int n;
    std::cin >> n;

    std::vector<edge> adj;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj.push_back({u, v, w});
    }

    DSU dsu(n);

    i64 res = 0;
    std::sort(adj.begin(), adj.end());
    for (auto [u, v, w] : adj)
    {
        if (dsu.same(u, v))
            continue;
        else
        {
            res += (dsu.siz[dsu.leader(u)] * dsu.siz[dsu.leader(v)] - 1) * (w + 1);
            dsu.merge(u, v);
        }
    }
    std::cout << res << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}