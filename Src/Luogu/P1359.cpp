#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            int w;
            std::cin >> w;
            adj[i].push_back({j, w});
        }

    std::vector<int> dis(n, inf);
    std::vector<bool> st(n, false);

    auto dijkstra = [&]()
    {
        dis[0] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> h;
        h.push({0, 0});
        while (h.size())
        {
            int u = h.top().second;
            h.pop();

            if (st[u])
                continue;
            st[u] = true;

            for (auto [v, w] : adj[u])
                if (dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w, h.push({dis[v], v});
        }
        return dis[n - 1];
    };
    std::cout << dijkstra() << '\n';

    return 0;
}