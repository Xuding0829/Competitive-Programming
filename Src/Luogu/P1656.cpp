#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int time = 0, cnt = 0;
    std::vector<int> dfn(n + 1), low(n + 1);
    std::vector<std::pair<int, int>> bridge;
    std::function<void(int, int)> tarjan = [&](int u, int fa)
    {
        dfn[u] = low[u] = ++time;
        for (auto v : adj[u])
        {
            if (!dfn[v])
            {
                tarjan(v, u);
                low[u] = std::min(low[u], low[v]);
                if (low[v] > dfn[u])
                    bridge.push_back({u, v});
            }
            else if (dfn[v] < low[u] && v != fa)
                low[u] = std::min(low[u], dfn[v]);
        }
    };
    tarjan(1, -1);

    std::sort(bridge.begin(), bridge.end());
    for (auto [u, v] : bridge)
        std::cout << u << ' ' << v << '\n';
    return 0;
}