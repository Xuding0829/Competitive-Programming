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
    }

    int sc = 0, dfncnt = 0, tp = 0;
    std::vector<int> dfn(n + 1), low(n + 1), siz(n + 1), scc(n + 1), stk(n + 1);
    std::vector<bool> vis(n + 1);
    std::function<void(int)> tarjan = [&](int u)
    {
        dfn[u] = low[u] = ++dfncnt;
        stk[++tp] = u, vis[u] = true;
        for (auto v : adj[u])
        {
            if (!dfn[v])
            {
                tarjan(v);
                low[u] = std::min(low[v], low[u]);
            }
            else if (vis[v])
                low[u] = std::min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u])
        {
            ++sc;
            int v;
            while (stk[tp] != u)
            {
                v = stk[tp--];
                scc[v] = sc;
                siz[sc]++;
                vis[v] = false;
            }
            v = stk[tp--];
            scc[v] = sc;
            siz[sc]++;
            vis[v] = false;
        }
    };
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);

    int res = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (siz[i] > 1)
            res++;
    }
    std::cout << res << '\n';
    return 0;
}