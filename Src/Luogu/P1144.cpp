#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 100003, inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> pre(n);
    std::vector<int> dis(n, inf);
    std::vector<bool> st(n, false);

    std::function<void(void)> dijkstra = [&]()
    {
        dis[0] = 0;
        pre[0] = 1;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> h;
        h.push({0, 0});
        while (h.size())
        {
            int u = h.top().second;
            h.pop();

            if (st[u])
                continue;
            st[u] = true;

            for (auto v : adj[u])
            {
                if (dis[v] > dis[u] + 1)
                {
                    dis[v] = dis[u] + 1;
                    pre[v] = pre[u];
                    h.push({dis[v], v});
                }
                else if (dis[v] == dis[u] + 1)
                {
                    (pre[v] += pre[u]) %= mod;
                }
            }
        }
    };

    dijkstra();

    for (int i = 0; i < n; i++)
        std::cout << pre[i] << '\n';

    return 0;
}