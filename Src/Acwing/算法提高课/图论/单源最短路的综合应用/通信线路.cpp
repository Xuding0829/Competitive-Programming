#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f, N = 1e3 + 10;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<std::pair<int, int>>> adj(n);

    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto check = [&](int x)
    {
        std::vector<int> dis(n, inf);
        dis[0] = 0;
        std::bitset<N> st;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        q.push({0, 0});
        while (q.size())
        {
            int t = q.top().second;
            q.pop();

            if (st[t])
                continue;
            st[t] = true;

            for (auto [v, w] : adj[t])
            {
                w = w > x;
                if (dis[v] > dis[t] + w)
                    dis[v] = dis[t] + w, q.push({dis[v], v});
            }
        }
        return dis[n - 1] <= k;
    };

    int l = 0, r = 1e6 + 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    if (r == 1e6 + 1)
        r = -1;
    std::cout << r << '\n';
    return 0;
}