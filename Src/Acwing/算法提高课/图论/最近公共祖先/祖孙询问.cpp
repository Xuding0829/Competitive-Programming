#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr int N = 4e4 + 100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int root;
    std::vector<int> adj[N];
    for (int i = 0; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        if (v == -1)
            root = u;
        else
            adj[u].push_back(v), adj[v].push_back(u);
    }

    std::vector<int> depth(N, inf);
    std::vector fa(N, std::vector<int>(16));
    auto bfs = [&](int root)
    {
        std::queue<int> q;
        q.push(root);
        depth[0] = 0;
        depth[root] = 1;
        while (q.size())
        {
            auto u = q.front();
            q.pop();

            for (auto v : adj[u])
            {
                if (depth[v] > depth[u] + 1)
                {
                    depth[v] = depth[u] + 1;
                    q.push(v);
                    fa[v][0] = u;
                    for (int k = 1; k <= 15; k++)
                    {
                        fa[v][k] = fa[fa[v][k - 1]][k - 1];
                    }
                }
            }
        }
    };

    bfs(root);

    auto lca = [&](int u, int v)
    {
        if (depth[u] < depth[v])
            std::swap(u, v);
        for (int k = 15; k >= 0; k--)
        {
            if (depth[fa[u][k]] >= depth[v])
                u = fa[u][k];
        }
        if (u == v)
            return u;
        for (int k = 15; k >= 0; k--)
        {
            if (fa[u][k] != fa[v][k])
                u = fa[u][k], v = fa[v][k];
        }
        return fa[u][0];
    };

    int m;
    std::cin >> m;
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        int p = lca(u, v);
        if (p == u)
            std::cout << "1\n";
        else if (p == v)
            std::cout << "2\n";
        else
            std::cout << "0\n";
    }

    return 0;
}