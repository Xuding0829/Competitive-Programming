#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> adj[n + 1];
    for (int u = 1, v; u <= n; u++)
    {
        while (std::cin >> v, v)
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

    for (int u = 1; u <= n; u++)
    {
        if (!dfn[u])
            tarjan(u);
    }

    std::vector<int> in(n + 1), out(n + 1);
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            int a = scc[u], b = scc[v];
            if (a != b)
                out[a]++, in[b]++;
        }
    }

    int a = 0, b = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (!in[i])
            a++;
        if (!out[i])
            b++;
    }

    std::cout << a << '\n';
    if (sc == 1)
        std::cout << "0\n";
    else
        std::cout << std::max(a, b) << '\n';
    return 0;
}