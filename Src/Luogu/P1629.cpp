#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    auto dijkstra = [&](int s, int e)
    {
        std::vector<int> dis(n, inf);
        std::vector<bool> st(n, false);
        dis[s] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> h;
        h.push({0, s});
        while (h.size())
        {
            int u = h.top().second;
            h.pop();

            if (st[u])
                continue;
            st[u] = true;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w, h.push({dis[v], v});
            }
        }
        return dis[e];
    };

    i64 res = 0;
    for (int i = 0; i < n; i++)
        res += dijkstra(0, i) + dijkstra(i, 0);
    std::cout << res << '\n';

    return 0;
}