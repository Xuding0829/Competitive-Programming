#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, s;
    while (std::cin >> n >> m >> s)
    {
        std::vector<std::pair<int, int>> adj[n + 1];
        while (m--)
        {
            int u, v, w;
            std::cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        int cnt;
        std::cin >> cnt;
        while (cnt--)
        {
            int st;
            std::cin >> st;
            adj[0].push_back({st, 0});
        }

        auto dijkstra = [&]()
        {
            std::vector<bool> st(n + 1);
            std::vector<int> dis(n + 1, inf);
            dis[0] = 0;

            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
            q.push({0, 0});
            while (q.size())
            {
                int u = q.top().second;
                q.pop();

                if (st[u])
                    continue;
                st[u] = true;

                for (auto [v, w] : adj[u])
                {
                    if (dis[v] > dis[u] + w)
                    {
                        dis[v] = dis[u] + w;
                        q.push({dis[v], v});
                    }
                }
            }
            return (dis[s] == inf ? -1 : dis[s]);
        };

        std::cout << dijkstra() << '\n';
    }

    return 0;
}