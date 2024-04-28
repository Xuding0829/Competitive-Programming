#include <bits/stdc++.h>

using i64 = long long;
constexpr int inf = 0x3f3f3f3f;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int p;
    std::cin >> p;
    std::vector<int> per(n + 1, inf), peo(n + 1);
    for (int i = 1; i <= p; i++)
    {
        int id, money;
        std::cin >> id >> money;
        peo[i] = id;
        per[id] = money;
    }

    int m;
    std::cin >> m;
    std::vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    int time = 0, sc = 0;
    std::vector<int> dfn(n + 1), low(n + 1), siz(n + 1), scc(n + 1), cos(n + 1, inf), id(n + 1, inf);
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
            ++sc;
            int v;
            id[sc] = u;
            while (stk.top() != u)
            {
                v = stk.top();
                stk.pop(), vis[v] = false;
                scc[v] = sc, siz[sc]++;
                cos[sc] = std::min(cos[sc], per[v]);
                id[sc] = std::min(id[sc], v);
            }
            v = stk.top();
            stk.pop(), vis[v] = false;
            scc[v] = sc, siz[sc]++;
            cos[sc] = std::min(cos[sc], per[v]);
            id[sc] = std::min(id[sc], v);
        }
    };

    for (int i = 1; i <= p; i++)
    {
        if (!dfn[peo[i]])
            tarjan(peo[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            std::cout << "NO\n";
            std::cout << i << '\n';
            return 0;
        }
    }

    std::vector<int> adj2[n + 1];
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            int a = scc[u], b = scc[v];
            if (a != b)
                adj2[a].push_back(b);
        }
    }

    std::vector<int> in(n + 1);
    for (int u = sc; u; u--)
    {
        for (auto v : adj2[u])
            in[v]++;
    }

    i64 res = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (in[i])
            continue;
        else
            res += cos[i];
    }
    std::cout << "YES\n";
    std::cout << res << '\n';
    return 0;
}