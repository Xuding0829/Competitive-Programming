#include <bits/stdc++.h>

using i64 = long long;

const int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b;
    while (std::cin >> n >> a >> b, n)
    {
        a--, b--;

        std::vector<bool> st(n);
        std::vector<int> adj[n];
        std::vector<int> dis(n, inf);
        for (int i = 0, x; i < n; i++)
        {
            std::cin >> x;
            int maxn = i + x, minn = i - x;
            if (maxn < n)
                adj[i].push_back(maxn);
            if (minn >= 0)
                adj[i].push_back(minn);
        }

        std::function<void(int)> dijkstra = [&](int a)
        {
            dis[a] = 0;
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> h;
            h.push({0, a});
            while (h.size())
            {
                int u = h.top().second;
                h.pop();

                if (st[u])
                    continue;
                st[u] = true;

                for (auto v : adj[u])
                {
                    if (dis[v] > dis[u] + 1)
                    {
                        dis[v] = dis[u] + 1;
                        h.push({dis[v], v});
                    }
                }
            }
        };

        dijkstra(a);

        std::cout << (dis[b] == inf ? -1 : dis[b]) << '\n';
    }

    return 0;
}