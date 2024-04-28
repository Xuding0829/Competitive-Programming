#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m, n || m)
    {
        std::vector<int> adj[n + 1];
        while (m--)
        {
            int u, v;
            std::cin >> u >> v;
            adj [u].push_back(v);
            adj[v].push_back(u);
        }

        int time = 0, res = 0;
        std::vector<int> dfn(n + 1), low(n + 1), cut(n + 1);
        std::function<void(int, bool)> tarjan = [&](int u, bool root = true)
        {
            int tot = 0;
            dfn[u] = low[u] = ++time;
            for (auto v : adj[u])
            {
                if (!dfn[v])
                {
                    tarjan(v, false);
                    low[u] = std::min(low[u], low[v]);
                    tot += (low[v] >= dfn[u]);
                }
                else
                    low[u] = std::min(low[u], dfn[v]);
            }
            res = std::max(res, tot + !root);
        };

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!dfn[i])
            {
                cnt++;
                tarjan(i, true);
            }
        }
        // std::cout << cnt << ' ' << res << '\n';
        std::cout << cnt + res - 1 << '\n';
    }
    return 0;
}