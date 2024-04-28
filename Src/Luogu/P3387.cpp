#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    std::vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    int time = 0, sc = 0;
    std::vector<int> dfn(n + 1), low(n + 1), scc(n + 1), siz(n + 1), s(n + 1);
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
                scc[v] = sc, siz[sc]++;
                s[sc] += a[v];
            }
            v = stk.top();
            stk.pop(), vis[v] = false;
            scc[v] = sc, siz[sc]++;
            s[sc] += a[v];
        }
    };

    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }

    std::vector<int> adj2[n + 1];
    std::vector<int> in(n + 1);
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            int a = scc[u], b = scc[v];
            if (a != b)
                adj2[a].push_back(b), in[b]++;
        }
    }

    std::vector<int> dis(n + 1);
    std::queue<int> q;
    for (int i = 1; i <= sc; i++)
    {
        if (!in[i])
            q.push(i), dis[i] = s[i];
    }
    while (q.size())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj2[u])
        {
            dis[v] = std::max(dis[v], dis[u] + s[v]);
            in[v]--;
            if (!in[v])
                q.push(v);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = std::max(res, dis[i]);
    std::cout << res << '\n';
    return 0;
}