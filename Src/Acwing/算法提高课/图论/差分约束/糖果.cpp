#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> adj[n + 1];
    while (k--)
    {
        int x, a, b;
        std::cin >> x >> a >> b;
        if (x == 1)
            adj[a].push_back({b, 0}), adj[b].push_back({a, 0});
        else if (x == 2)
            adj[a].push_back({b, 1});
        else if (x == 3)
            adj[b].push_back({a, 0});
        else if (x == 4)
            adj[b].push_back({a, 1});
        else
            adj[a].push_back({b, 0});
    }
    for (int i = 1; i <= n; i++)
        adj[0].push_back({i, 1});

    std::vector<i64> dis(n + 1, -inf);
    auto spfa = [&]()
    {
        std::vector<bool> vis(n + 1);
        std::vector<int> cnt(n + 1);
        dis[0] = 0, vis[0] = true;

        int k = 0;
        std::queue<int> q;
        q.push(0);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (auto [v, w] : adj[u])
            {
                if (dis[v] < dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n + 1)
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

    if (spfa())
        std::cout << "-1\n";
    else
    {
        i64 res = 0;
        for (int i = 1; i <= n; i++)
            res += dis[i];
        std::cout << res << '\n';
    }
    return 0;
}