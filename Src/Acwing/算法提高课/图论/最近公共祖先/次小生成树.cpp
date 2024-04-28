#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;
struct edge
{
    int u, v, w;
    bool f;
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

    std::vector<edge> e(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        e[i] = {u, v, w};
    }

    DSU dsu(n);
    auto kruskal = [&]
    {
        i64 sum = 0;
        std::sort(e.begin(), e.end());
        for (auto &[u, v, w, f] : e)
        {
            if (!dsu.same(u, v))
            {
                dsu.merge(u, v);
                sum += w;
                f = true;
            }
        }
        return sum;
    };
    i64 sum = kruskal();

    std::vector<std::pair<int, int>> adj[n];
    for (auto [u, v, w, f] : e)
    {
        if (f)
        {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    std::vector<int> dep(n, inf);
    std::vector fa(n, std::vector<int>(17));
    std::vector d1(n, std::vector<int>(17));
    std::vector d2(n, std::vector<int>(17));

    auto bfs = [&]() -> void
    {
        dep[0] = 1;
        std::queue<int> q;
        q.push(0);
        while (q.size())
        {
            auto u = q.front();
            q.pop();

            for (auto [v, w] : adj[u])
            {
                if (dep[v] > dep[u] + 1)
                {
                    dep[v] = dep[u] + 1;
                    q.push(v);

                    fa[v][0] = u;
                    d1[v][0] = w, d2[v][0] = -inf;
                    for (int k = 1; k <= 16; k++)
                    {
                        int anc = fa[v][k - 1];
                        fa[v][k] = fa[anc][k - 1];
                        int dist[] = {d1[v][k - 1], d2[v][k - 1], d1[anc][k - 1], d2[anc][k - 1]};
                        d1[v][k] = d2[v][k] = -inf;
                        for (auto d : dist)
                        {
                            if (d > d1[v][k])
                                d2[v][k] = d1[v][k], d1[v][k] = d;
                            else if (d != d1[v][k] && d > d2[v][k])
                                d2[v][k] = d;
                        }
                    }
                }
            }
        }
    };
    bfs();

    auto lca = [&](int u, int v, int w)
    {
        std::vector<int> dist;
        if (dep[u] < dep[v])
            std::swap(u, v);
        for (int k = 16; k >= 0; k--)
        {
            if (dep[fa[u][k]] >= dep[v])
            {
                dist.push_back(d1[u][k]);
                dist.push_back(d2[u][k]);
                u = fa[u][k];
            }
        }
        if (u != v)
        {
            for (int k = 16; k >= 0; k--)
            {
                if (fa[u][k] != fa[v][k])
                {
                    dist.push_back(d1[u][k]);
                    dist.push_back(d2[u][k]);
                    dist.push_back(d1[v][k]);
                    dist.push_back(d2[v][k]);
                    u = fa[u][k];
                    v = fa[v][k];
                }
            }
            dist.push_back(d1[u][0]);
            dist.push_back(d1[v][0]);
        }

        int dis1 = -inf, dis2 = -inf;
        for (auto d : dist)
        {
            if (d > dis1)
                dis2 = dis1, dis1 = d;
            else if (d != dis1 && d > dis2)
                dis2 = d;
        }

        if (w > dis1)
            return w - dis1;
        if (w > dis2)
            return w - dis2;
        return inf;
    };

    i64 res = 1e18;
    for (auto [u, v, w, f] : e)
    {
        if (!f)
            res = std::min(res, sum + (i64)lca(u, v, w));
    }
    std::cout << res << '\n';
    return 0;
}