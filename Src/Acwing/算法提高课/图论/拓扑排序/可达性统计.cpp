#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 3e4 + 10;
std::bitset<N> f[N];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> deg(n + 1), adj[n + 1], adj2[n + 1];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u);
        deg[v]++;
    }

    std::queue<int> q;
    std::vector<int> t;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            q.push(i);

    while (q.size())
    {
        auto u = q.front();
        q.pop();
        t.push_back(u);

        for (auto v : adj[u])
        {
            --deg[v];
            if (!deg[v])
                q.push(v);
        }
    }

    std::reverse(t.begin(), t.end());

    for (auto u : t)
    {
        f[u][u] = 1;
        for (auto v : adj[u])
            f[u] |= f[v];
    }

    for (int i = 1; i <= n; i++)
        std::cout << f[i].count() << '\n';
    return 0;
}