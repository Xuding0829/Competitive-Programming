#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f, N = 2520, M = 6200 * 2;

struct Node
{
    int next, value;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, s, t;
    std::cin >> n >> m >> s >> t;

    std::vector<Node> g[N];

    while (m--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        g[a].push_back({b, c}), g[b].push_back({a, c});
    }

    std::vector<int> dis(n + 1, inf);

    // spfa
    std::function<int(void)> spfa = [&]()
    {
        bool st[n];

        std::queue<int> q;
        q.push(s);
        dis[s] = 0, st[s] = true;

        while (q.size())
        {
            int u = q.front();
            q.pop();
            st[u] = false;

            for (int i = 0; i < g[u].size(); i++)
            {
                int j = g[u][i].next, w = g[u][i].value;
                if (dis[j] > dis[u] + w)
                {
                    dis[j] = dis[u] + w;
                    if (!st[j])
                    {
                        q.push(j), st[j] = true;
                    }
                }
            }
        }
        return dis[t];
    };

    // dijkstra
    std::function<int(void)> dijkstra = [&]()
    {
        std::bitset<N> st;

        dis[s] = 0;
        for (int i = 1; i <= n; i++)
        {
            int t = -1;
            for (int j = 1; j <= n; j++)
                if (!st[j] && (t == -1 || dis[j] < dis[t]))
                    t = j;

            st[t] = true;
            for (int j = 1; j <= n; j++)
                for (int k = 0; k < g[t].size(); k++)
                    if (j == g[t][k].next)
                        dis[j] = std::min(dis[j], dis[t] + g[t][k].value);
        }
        return dis[t];
    };

    // dijkstra_heap
    std::function<int(void)> dijkstra_heap = [&]()
    {
        std::bitset<N> st;

        dis[s] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;
        heap.push({0, s});
        while (heap.size())
        {
            auto t = heap.top();
            heap.pop();

            int d = t.first, node = t.second;
            if (st[node])
                continue;
            st[node] = true;
            for (int i = 0; i < g[node].size(); i++)
            {
                int to = g[node][i].next, w = g[node][i].value;
                dis[to] = std::min(dis[to], dis[node] + w), heap.push({dis[to], to});
            }
        }
        return dis[t];
    };

    std::cout << dijkstra_heap() << '\n';

    return 0;
}