#include <bits/stdc++.h>

using i64 = long long;
using PII = std::pair<int, int>;

const int N = 50010, M = 200010, inf = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
int dis[7][N], id[10];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(int start, int dis[])
{
    memset(dis, 0x3f, N * 4);
    memset(st, false, sizeof(st));

    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> heap;
    dis[start] = 0;
    heap.push({0, start});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int pre = t.second, dist = t.first;

        if (st[pre])
            continue;
        st[pre] = true;

        for (int i = h[pre]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[pre] + w[i])
                dis[j] = dis[pre] + w[i], heap.push({dis[j], j});
        }
    }
}

int dfs(int u, int start, int distance)
{
    if (u == 6)
        return distance;

    int res = inf;
    for (int i = 2; i <= 6; i++)
    {
        if (!st[i])
        {
            int next = id[i];
            st[i] = true;
            res = std::min(res, dfs(u + 1, i, distance + dis[start][next]));
            st[i] = false;
        }
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(h, -1, sizeof(h));

    int n, m;
    std::cin >> n >> m;

    id[1] = 1;
    for (int i = 2; i <= 6; i++)
        std::cin >> id[i];

    while (m--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    for (int i = 1; i <= 6; i++)
        dijkstra(id[i], dis[i]);

    memset(st, false, sizeof(st));
    std::cout << dfs(1, 1, 0) << '\n';

    return 0;
}

/*
#include<bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f, N = 1e5 +100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> source(6, 1);
    for (int i = 1; i < 6; i++)
        std::cin >> source[i];

    std::vector<std::pair<int, int>> adj[n];
    while(m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::vector<std::vector<int>> dis(6, std::vector<int>(N, inf));
    std::function<void(int)> dijkstra = [&](int start)
    {
        std::bitset<N> st;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> h;
        h.push({0, start});
        dis[start][start] = 0;
        while(h.size())
        {
            auto t = h.top().second, dist = h.top().first;
            h.pop();

            if(st[t])
                continue;
            st[t] = true;

            for (auto [v, w] : adj[t])
                if(dis[start][v] > dis[start][t] + w)
                    dis[start][v] = dis[start][t] + w;
        }
    };

    for (int i = 1; i < 6; i++)
        dijkstra(i);

    std::bitset<6> st;
    std::function<int(int, int, int)> dfs = [&](int u, int start, int d)
    {
        if(u == 6)
            return d;

        int res = inf;
        for (int i = 1; i < 6; i++)
        {
            if(st[i])
                continue;
            st[i] = true;
            int next = source[i];
            res = std::min(res, dfs(u + 1, i, d + dis[start][next]));
            st[i] = false;
        }
        return res;
    };
    std::cout << dfs(1, 0, 0) << '\n';

    return 0;
}
*/