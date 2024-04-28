#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 2e4 + 10;
std::vector<int> deg(N), dis(N, 1), stk;
std::vector<std::pair<int, int>> adj[N];
std::vector<bool> vis(N);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        std::fill(vis.begin(), vis.end(), false);

        int t;
        std::cin >> t;
        int st = n, ed = 1;
        while (t--)
        {
            int stop;
            std::cin >> stop;
            st = std::min(st, stop);
            ed = std::max(ed, stop);
            vis[stop] = true;
        }

        int ver = n + i;
        for (int j = st; j <= ed; j++)
        {
            if (vis[j])
                adj[ver].push_back({j, 0}), deg[j]++;
            else
                adj[j].push_back({ver, 1}), deg[ver]++;
        }
    }

    std::queue<int> q;
    for (int i = 1; i <= n + m; i++)
    {
        if (!deg[i])
            q.push(i);
    }
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        stk.push_back(u);

        for (auto [v, w] : adj[u])
        {
            --deg[v];
            if (!deg[v])
                q.push(v);
        }
    }

    for (auto u : stk)
        for (auto [v, w] : adj[u])
            dis[v] = std::max(dis[v], dis[u] + w);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = std::max(res, dis[i]);
    std::cout << res << '\n';
    return 0;
}