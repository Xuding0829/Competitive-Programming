#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 110, inf = 0x3f3f3f;

struct Edge
{
    int to, value;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1, inf));
    while (m--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        g[a][b] = g[b][a] = std::min(g[a][b], c);
    }

    std::function<int(void)> floyd = [&]()
    {
        int res = 0;

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j)
                    g[i][j] = 0;

        for (int i = 1; i <= n; i++)
            if (g[1][i] == inf)
            {
                res = -1;
                break;
            }
            else
                res = std::max(res, g[1][i]);

        return res;
    };

    std::function<int(void)> dijkstra = [&]()
    {
        int res = 0;

        std::bitset<N> st;

        for (int i = 1; i <= n; i++)
        {
            int t = -1;
            for (int j = 1; j <= n; j++)
                if (!st[j] && (t == -1 || g[1][j] < g[1][t]))
                    t = j;

            st[t] = true;
            for (int j = 1; j <= n; j++)
                g[1][j] = std::min(g[1][j], g[1][t] + g[t][j]);
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j)
                    g[i][j] = 0;

        for (int i = 1; i <= n; i++)
            if (g[1][i] == inf)
            {
                res = -1;
                break;
            }
            else
                res = std::max(res, g[1][i]);

        return res;
    };

    std::function<int(void)> dijkstra_heap = [&]()
    {
        std::bitset<N> st;
        g[1][1] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        q.push({0, 1});
        while (q.size())
        {
            auto t = q.top();
            q.pop();

            int dis = t.first, node = t.second;

            if (st[node])
                continue;
            st[node] = true;

            for (int i = 1; i <= n; i++)
            {
                if (g[node][i] != inf)
                {
                    if (g[1][i] > g[1][node] + g[node][i])
                        g[1][i] = g[1][node] + g[node][i];
                    q.push({g[1][i], i});
                }
            }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j)
                    g[i][j] = 0;

        int res = 0;
        for (int i = 1; i <= n; i++)
            if (g[1][i] == inf)
            {
                res = -1;
                break;
            }
            else
                res = std::max(res, g[1][i]);
        return res;
    };

    return 0;
}
