#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> f(n);
    for (int i = 0; i < n; i++)
        std::cin >> f[i];

    std::vector<std::pair<int, int>> adj[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    auto check = [&](double mid)
    {
        std::vector<bool> vis(n);
        std::vector<int> cnt(n);
        std::vector<double> dis(n);

        std::queue<int> q;
        for (int i = 0; i < n; i++)
            vis[i] = true, q.push(i);

        while (q.size())
        {
            int u = q.front();
            q.pop();

            vis[u] = false;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] < dis[u] + f[u] - mid * w)
                {
                    dis[v] = dis[u] + f[u] - mid * w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n)
                        return true;
                    if (!vis[v])
                        q.push(v), vis[v] = true;
                }
            }
        }
        return false;
    };

    double l = 0, r = 1000;
    while (r - l >= 1e-4)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    std::cout << std::fixed << std::setprecision(2) << l << '\n';
    return 0;
}