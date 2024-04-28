#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> adj[50010];
    for (int i = 1; i <= 50001; i++)
        adj[i - 1].push_back({i, 0}), adj[i].push_back({i - 1, -1});
    while (n--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        adj[a].push_back({b + 1, c});
    }

    auto spfa = [&]()
    {
        std::vector<int> dis(50010, -inf);
        std::vector<bool> vis(50010);

        std::queue<int> q;
        q.push(0), vis[0] = true, dis[0] = 0;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            vis[u] = false;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] < dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!vis[v])
                    {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return dis[50001];
    };

    std::cout << spfa() << '\n';

    return 0;
}