#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::pair<int, int>> adj[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    while (k--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, -w});
    }

    auto spfa = [&]()
    {
        std::vector<bool> vis(n);
        std::vector<int> dis(n), cnt(n);
        std::queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(i);
            vis[i] = true;
        }

        while (q.size())
        {
            int u = q.front();
            q.pop();

            vis[u] = false;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] == n)
                        return true;
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return false;
    };

    std::cout << (spfa() ? "YES\n" : "NO\n");
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