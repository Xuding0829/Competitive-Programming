#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, i64>> adj[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::vector<bool> vis(n);
    std::vector<i64> dis(n, inf);
    dis[0] = 0;
    std::vector<int> pre(n, -1);

    auto dijkstra = [&]()
    {
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> q;
        q.push({dis[0], 0});
        while (q.size())
        {
            auto u = q.top().second;
            q.pop();

            if (vis[u])
                continue;
            vis[u] = true;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    pre[v] = u;
                    q.push({dis[v], v});
                }
            }
        }

        return dis[n - 1];
    };

    i64 res = dijkstra();
    if (res == inf)
        std::cout << -1 << '\n';
    else
    {
        std::stack<int> stk;
        stk.push(n - 1);
        for (int i = pre[n - 1]; ~i; i = pre[i])
            stk.push(i);
        while (stk.size())
            std::cout << stk.top() + 1 << ' ', stk.pop();
    }

    return 0;
}