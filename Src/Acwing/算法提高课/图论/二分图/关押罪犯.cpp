#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> adj[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto check = [&](int mid)
    {
        std::vector<int> col(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (col[i] != -1)
                continue;

            std::queue<int> q;
            q.push(i), col[i] = 0;
            while (q.size())
            {
                auto u = q.front();
                q.pop();

                for (auto [v, w] : adj[u])
                {
                    if (w <= mid)
                        continue;
                    if (col[v] == col[u])
                        return false;
                    if (col[v] == -1)
                    {
                        col[v] = !col[u];
                        q.push(v);
                    }
                }
            }
        }
        return true;
    };

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << '\n';

    return 0;
}