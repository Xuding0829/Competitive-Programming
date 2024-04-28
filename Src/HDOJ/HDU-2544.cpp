// https : // vjudge.net/problem/HDU-2544
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <functional>

using i64 = long long;

constexpr int inf = 0x3f3f3f, N = 11100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m && (n || m))
    {
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        while (m--)
        {
            int u, v, w;
            std::cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        std::vector<int> dis(n + 1, inf);

        std::function<void(void)> dijkstra_heap = [&]()
        {
            dis[1] = 0;
            std::bitset<N> st;

            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
            q.push({0, 1});
            while (q.size())
            {
                int t = q.top().second;
                q.pop();

                if (st[t])
                    continue;
                st[t] = true;

                for (int i = 0; i < adj[t].size(); i++)
                {
                    int v = adj[t][i].first, w = adj[t][i].second;
                    if (dis[v] > dis[t] + w)
                        dis[v] = dis[t] + w, q.push({dis[v], v});
                }
            }
        };

        dijkstra_heap();

        std::cout << dis[n] << '\n';
    }

    return 0;
}