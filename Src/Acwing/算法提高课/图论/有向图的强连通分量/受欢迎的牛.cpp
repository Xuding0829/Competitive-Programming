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

    int time = 0, sc = 0;
    std::vector<int> dfn(n + 1), low(n + 1), siz(n + 1), scc(n + 1);
    std::vector<bool> vis(n + 1);
    std::stack<int> stk;
    std::function<void(int)> tarjan = [&](int u)
    {
        dfn[u] = low[u] = ++time;
        stk.push(u), vis[u] = true;
        for (auto v : adj[u])
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
                scc[v] = sc;
                siz[sc]++;
                stk.pop();
                vis[v] = false;
            }
            v = stk.top();
            scc[v] = sc;
            siz[sc]++;
            stk.pop();
            vis[v] = false;
        }
    };

    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }

    std::vector<int> out(n + 1);
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            int a = scc[u], b = scc[v];
            if (a != b)
                out[a]++;
        }
    }

    int res = 0, zero = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (!out[i])
        {
            zero++, res += siz[i];
            if (zero > 1)
            {
                res = 0;
                break;
            }
        }
    }
    std::cout << res << '\n';
    return 0;
}