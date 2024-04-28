#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m1, m2;
    std::cin >> n >> m1 >> m2;

    std::vector<std::pair<int, int>> adj[n + 1];
    for (int i = 1; i < n; i++)
        adj[i + 1].push_back({i, 0});
    while (m1--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a > b)
            std::swap(a, b);
        adj[a].push_back({b, c});
    }
    while (m2--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a > b)
            std::swap(a, b);
        adj[b].push_back({a, -c});
    }

    std::vector<int> dis(n + 1, 0x3f3f3f3f);
    auto spfa = [&](int size)
    {
        std::vector<bool> vis(n + 1);
        std::vector<int> cnt(n + 1);

        std::queue<int> q;
        for (int i = 1; i <= size; i++)
            q.push(i), vis[i] = true, dis[i] = 0;

        while (q.size())
        {
            auto u = q.front();
            q.pop();
            vis[u] = false;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n + 1)
                        return true;
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return false;
    };

    if (spfa(n))
        std::cout << "-1\n";
    else
    {
        std::fill(dis.begin(), dis.end(), 0x3f3f3f3f);
        spfa(1);
        if (dis[n] == 0x3f3f3f3f)
            std::cout << "-2\n";
        else
            std::cout << dis[n] << '\n';
    }

    return 0;
}