#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    a--, b--;

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bool res = false;
    std::set<int> s;
    s.insert(0);

    auto bfs = [&]() -> void
    {
        std::vector<int> dis(n);
        std::vector<bool> st(n, false);

        std::queue<int> q;
        q.push(a);
        dis[a] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();

            if (st[u])
                continue;
            st[u] = true;

            for (auto [v, w] : adj[u])
            {
                if (!st[v] && v != b)
                {
                    dis[v] = dis[u] ^ w;
                    s.insert(dis[v]);
                    q.push(v);
                }
            }
        }
    };

    auto bfs2 = [&]() -> void
    {
        std::vector<int> dis(n);
        std::vector<bool> st(n, false);

        std::queue<int> q;
        q.push(b);
        dis[b] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();

            if (st[u])
                continue;
            st[u] = true;

            for (auto [v, w] : adj[u])
            {
                if (!st[v])
                {
                    dis[v] = dis[u] ^ w;
                    if (s.count(dis[v]))
                        res = true;
                    q.push(v);
                }
            }
        }
    };

    bfs();

    bfs2();

    if (res)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}