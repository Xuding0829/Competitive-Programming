#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n + 1];
    std::vector vis(n + 1, std::vector<int>(n + 1));
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        if (vis[u][v])
            continue;
        vis[u][v] = vis[v][u] = true;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int time = 0, dc = 0;
    std::vector<int> dfn(n + 1), low(n + 1), dcc(n + 1), fa(n + 1);
    std::vector<std::pair<int, int>> bridge;
    std::stack<int> stk;
    std::function<void(int)> tarjan = [&](int u)
    {
        dfn[u] = low[u] = ++time;
        stk.push(u);
        for (auto v : adj[u])
        {
            if (!dfn[v])
            {
                fa[v] = u;
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
                if (low[v] > dfn[u])
                    bridge.push_back({u, v});
            }
            else if (v != fa[u])
                low[u] = std::min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u])
        {
            int v;
            ++dc;
            while (stk.top() != u)
            {
                v = stk.top();
                stk.pop();
                dcc[v] = dc;
            }
            v = stk.top();
            stk.pop();
            dcc[v] = dc;
        }
    };

    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }

    std::vector<int> in(n + 1);
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            int a = dcc[u], b = dcc[v];
            if (a != b)
                in[b]++;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= dc; i++)
    {
        if (in[i] == 1)
            cnt++;
    }
    std::cout << (cnt + 1) / 2 << '\n';
    return 0;
}
/*
2 2
1 2
1 2
*/