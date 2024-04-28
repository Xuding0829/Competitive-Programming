#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, mod;
    std::cin >> n >> m >> mod;

    std::vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    int time = 0, sc = 0;
    std::vector<int> dfn(n + 1), low(n + 1), scc(n + 1), siz(n + 1);
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

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);

    std::unordered_set<i64> mp;
    std::vector<int> adj2[sc + 1];
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            int a = scc[u], b = scc[v];
            i64 hash = a * 1e6 + b;
            if (a != b && !mp.count(hash))
                adj2[a].push_back(b), mp.insert(hash);
        }
    }

    std::vector<int> f(n + 1), g(n + 1);
    for (int u = sc; u; u--)
    {
        if (!f[u])
        {
            f[u] = siz[u];
            g[u] = 1;
        }
        for (auto v : adj2[u])
        {
            if (f[v] < f[u] + siz[v])
                f[v] = f[u] + siz[v], g[v] = g[u];
            else if (f[v] == f[u] + siz[v])
                (g[v] += g[u]) %= mod;
        }
    }

    int maxn = 0, cnt = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (f[i] > maxn)
            maxn = f[i], cnt = g[i];
        else if (f[i] == maxn)
            (cnt += g[i]) %= mod;
    }
    std::cout << maxn << '\n';
    std::cout << cnt << '\n';
    return 0;
}