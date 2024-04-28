#include <bits/stdc++.h>

using i64 = long long;
constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> dep(n + 1, inf);
    std::vector fa(n + 1, std::vector<int>(17));

    std::queue<int> q;
    q.push(1);
    dep[0] = 0, dep[1] = 1;
    while (q.size())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (dep[v] > dep[u] + 1)
            {
                dep[v] = dep[u] + 1;
                q.push(v);
                fa[v][0] = u;
                for (int k = 1; k <= 16; k++)
                    fa[v][k] = fa[fa[v][k - 1]][k - 1];
            }
        }
    }

    auto lca = [&](int u, int v)
    {
        if (dep[u] < dep[v])
            std::swap(u, v);
        for (int k = 16; k >= 0; k--)
        {
            if (dep[fa[u][k]] >= dep[v])
                u = fa[u][k];
        }

        if (u == v)
            return u;

        for (int k = 16; k >= 0; k--)
        {
            if (fa[u][k] != fa[v][k])
                u = fa[u][k], v = fa[v][k];
        }
        return fa[u][0];
    };

    std::vector<int> d(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        int p = lca(u, v);
        d[u]++, d[v]++, d[p] -= 2;
    }

    int res = 0;
    std::function<int(int, int)> dfs = [&](int u, int fa)
    {
        int tmp = d[u];
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            int x = dfs(v, u);
            if (x == 0)
                res += m;
            else if (x == 1)
                res++;
            tmp += x;
        }
        return tmp;
    };
    dfs(1, 0);
    std::cout << res << '\n';
    return 0;
}