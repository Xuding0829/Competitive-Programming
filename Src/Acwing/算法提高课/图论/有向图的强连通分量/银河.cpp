#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> adj[n + 1];
    for (int i = 1; i <= n; i++)
        adj[0].push_back({i, 1});
    while (m--)
    {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 1)
            adj[u].push_back({v, 0}), adj[v].push_back({u, 0});
        else if (t == 2)
            adj[u].push_back({v, 1});
        else if (t == 3)
            adj[v].push_back({u, 0});
        else if (t == 4)
            adj[v].push_back({u, 1});
        else
            adj[u].push_back({v, 0});
    }

    int time = 0, sc = 0;
    std::vector<int> dfn(n + 1), low(n + 1), scc(n + 1), siz(n + 1);
    std::vector<bool> vis(n + 1);
    std::stack<int> stk;
    std::function<void(int)> tarjan = [&](int u)
    {
        dfn[u] = low[u] = ++time;
        stk.push(u), vis[u] = true;
        for (auto [v, w] : adj[u])
        {
            if (!dfn[v])
            {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            }
            else if (vis[v])
                low[u] = std::min(low[u], dfn[v]);
        }

        if (dfn[u] == low[u])
        {
            sc++;
            int v;
            while (stk.top() != u)
            {
                v = stk.top();
                stk.pop(), vis[v] = false;
                scc[v] = sc;
                siz[sc]++;
            }
            v = stk.top();
            stk.pop(), vis[v] = false;
            scc[v] = sc;
            siz[sc]++;
        }
    };
    tarjan(0);

    bool flag = true;
    std::vector<std::pair<int, int>> adj2[sc + 1];
    for (int u = 0; u <= n; u++)
    {
        for (auto [v, w] : adj[u])
        {
            int a = scc[u], b = scc[v];
            if (a == b)
            {
                if (w > 0)
                {
                    flag = false;
                    break;
                }
            }
            else
                adj2[a].push_back({b, w});
        }
    }

    if (!flag)
        std::cout << "-1\n";
    else
    {
        std::vector<int> dis(sc + 1);
        for (int u = sc; u; u--)
        {
            for (auto [v, w] : adj2[u])
                dis[v] = std::max(dis[v], dis[u] + w);
        }

        i64 res = 0;
        for (int i = 1; i <= sc; i++)
            res += (i64)dis[i] * siz[i];
        std::cout << res << '\n';
    }

    return 0;
}