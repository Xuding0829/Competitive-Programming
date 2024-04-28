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
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    auto spfa = [&]()
    {
        std::vector<int> dis(n, -inf);
        std::vector<bool> st(n, false);
        dis[0] = 0;
        std::queue<int> q;
        q.push(0);
        st[0] = true;

        while (q.size())
        {
            int u = q.front();
            q.pop();
            st[u] = false;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] < dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!st[v])
                    {
                        q.push(v);
                        st[v] = true;
                    }
                }
            }
        }
        return dis[n - 1] > -inf / 2 ? dis[n - 1] : -1;
    };

    std::cout << spfa() << '\n';

    return 0;
}