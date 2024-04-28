#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

using i64 = long long;
struct node
{
    int s, d, u;
    bool operator>(const node &t) const
    {
        return s > t.s;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> adj[n], adj2[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj2[v].push_back({u, w});
    }

    int st, ed, k;
    std::cin >> st >> ed >> k;
    st--, ed--;
    if (st == ed)
        k++;

    std::vector<int> f(n, 0x3f3f3f3f);
    std::vector<bool> vis(n);
    auto dijkstra = [&]() -> void
    {
        f[ed] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        q.push({0, ed});
        while (q.size())
        {
            auto [d, u] = q.top();
            q.pop();

            if (vis[u])
                continue;
            vis[u] = true;

            for (auto [v, w] : adj2[u])
            {
                if (f[v] > f[u] + w)
                {
                    f[v] = f[u] + w;
                    q.push({f[v], v});
                }
            }
        }
    };
    dijkstra();

    std::vector<int> cnt(n);
    auto astar = [&]()
    {
        std::priority_queue<node, std::vector<node>, std::greater<node>> q;
        q.push({f[st], 0, st});
        while (q.size())
        {
            auto [s, distance, u] = q.top();
            q.pop();

            cnt[u]++;
            if (cnt[ed] == k)
                return distance;

            for (auto [v, w] : adj[u])
            {
                if (cnt[v] < k)
                    q.push({distance + w + f[v], distance + w, v});
            }
        }
        return -1;
    };
    std::cout << astar() << '\n';

    return 0;
}