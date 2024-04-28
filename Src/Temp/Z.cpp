#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

void solve()
{
    int n, m, k, p;
    std::cin >> n >> m >> k >> p;

    std::vector<std::pair<int, int>> adj[n], adj2[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj2[v].push_back({u, w});
    }

    std::vector<int> dis(n, inf);
    auto dijkstra = [&]()
    {
        std::vector<bool> vis(n);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        q.push({0, 0}), dis[0] = 0;
        while (q.size())
        {
            auto t = q.top();
            q.pop();

            int u = t.second;
            if (vis[u])
                continue;
            vis[u] = true;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
    };

    dijkstra();

    bool flag = false;
    std::vector st(n, std::vector<bool>(k + 1));
    std::vector f(n, std::vector<int>(k + 1, -1));
    f[0][0] = 1; // f[i][j] 表示到达i且多走j的方案数
    std::function<int(int, int)> dfs = [&](int u, int j)
    {
        if (~f[u][j])
            return f[u][j];

        st[u][j] = true;
        f[u][j] = 0;
        for (auto [v, w] : adj2[u])
        {
            int tmp = j + dis[u] - (dis[v] + w);
            if (tmp >= 0)
            {
                if (st[v][tmp])
                    flag = false;
                (f[u][j] += dfs(v, tmp)) %= p;
            }
        }
        st[u][j] = false;
        return f[u][j];
    };

    int res = 0;
    for (int i = 0; i <= k; i++)
        (res += dfs(n - 1, i)) %= p;

    if (!flag)
        std::cout << "-1\n";
    else
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