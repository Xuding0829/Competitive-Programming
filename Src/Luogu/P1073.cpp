#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> price(n);
    for (auto &v : price)
        std::cin >> v;

    std::vector<int> adj[n], adj2[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(v);
        adj2[v].push_back(u);
        if (w == 2)
        {
            adj[v].push_back(u);
            adj2[u].push_back(v);
        }
    }

    std::vector<int> maxn(n, -inf), minn(n, inf);

    std::function<void(int, int)> dfs_min = [&](int u, int m)
    {
        if (m >= minn[u])
            return;
        m = std::min(m, price[u]);
        minn[u] = m;

        for (auto v : adj[u])
        {
            dfs_min(v, m);
        }
    };

    std::function<void(int, int)> dfs_max = [&](int u, int m)
    {
        if (m <= maxn[u])
            return;
        m = std::max(m, price[u]);
        maxn[u] = m;

        for (auto v : adj2[u])
            dfs_max(v, m);
    };

    dfs_min(0, price[0]);
    dfs_max(n - 1, price[n - 1]);

    int res = 0;
    for (int i = 0; i < n; i++)
        res = std::max(res, maxn[i] - minn[i]);
    std::cout << res << '\n';

    return 0;
}