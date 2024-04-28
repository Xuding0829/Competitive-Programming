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

    int n, k;
    std::cin >> n >> k;

    int sum = 0;
    std::vector<edge> adj(k);
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[i] = {u, v, w};
        sum += w;
    }

    auto prim = [&]()
    {
        std::vector<bool> vis(n);
        std::vector<int> dis(n, inf);
        dis[0] = 0;

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int t = -1;
            for (int j = 0; j < n; j++)
            {
                if (!vis[j] && (t == -1 || dis[t] > dis[j]))
                    t = j;
            }

            res += dis[t];
            vis[t] = true;

            // for (int j = 0; j < n; j++)
            // dis[j] = std::min(dis[j], g[t][j]);
        }
        return res;
    };

    auto kruskal = [&]()
    {
        std::sort(adj.begin(), adj.end());

        DSU dsu(n);
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

        return sum - res;
    };

    // std::cout << prim() << '\n';

    std::cout << kruskal() << '\n';

    return 0;
}