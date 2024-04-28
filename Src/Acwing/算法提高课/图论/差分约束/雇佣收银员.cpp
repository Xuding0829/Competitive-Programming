#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

void solve()
{
    std::vector<int> r(25);
    for (int i = 1; i <= 24; i++)
        std::cin >> r[i];

    int n;
    std::cin >> n;
    std::vector<int> t(25);
    for (int i = 0, x; i < n; i++)
        std::cin >> x, t[x + 1]++;

    auto spfa = [&](int x)
    {
        std::vector<std::pair<int, int>> adj[100];
        for (int i = 1; i <= 24; i++)
        {
            adj[i - 1].push_back({i, 0});
            adj[i].push_back({i - 1, -t[i]});
        }
        for (int i = 8; i <= 24; i++)
            adj[i - 8].push_back({i, r[i]});
        for (int i = 1; i <= 7; i++)
            adj[i + 16].push_back({i, r[i] - x});
        adj[0].push_back({24, x}), adj[24].push_back({0, -x});

        std::vector<int> dis(25, -inf);
        std::vector<bool> vis(25);
        std::vector<int> cnt(25);

        std::queue<int> q;
        q.push(0), dis[0] = 0, vis[0] = true;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            vis[u] = false;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] < dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;

                    if (cnt[v] >= 25)
                        return false;

                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    };

    for (int i = 0; i <= 1000; i++)
    {
        if (spfa(i))
        {
            std::cout << i << '\n';
            return;
        }
    }
    std::cout << "No Solution\n";
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