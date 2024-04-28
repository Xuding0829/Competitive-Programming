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

    int n, m, root;
    std::cin >> n >> m >> root;
    root--;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<std::pair<int, int>> query[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        query[u].push_back({v, i});
        query[v].push_back({u, i});
    }

    DSU dsu(n);
    std::vector<int> res(m);
    std::vector<bool> vis(n);

    std::function<void(int)> tarjan = [&](int u)
    {
        vis[u] = true;
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                tarjan(v);
                dsu.merge(u, v);
            }
        }

        for (auto q : query[u])
        {
            int v = q.first, i = q.second;
            if (vis[v])
                res[i] = dsu.leader(v);
        }
    };
    tarjan(root);

    for (int i = 0; i < m; i++)
        std::cout << res[i] + 1 << '\n';
    return 0;
}