#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2010;

struct edge
{
    int to;
    double w;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<double>> g(n + 1, std::vector<double>(n + 1));
    while (m--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        double t = (100.0 - c) / 100.0 * 1.0;
        g[a][b] = g[b][a] = std::max(g[a][b], t);
    }

    int s, t;
    std::cin >> s >> t;

    std::bitset<N> st;
    std::vector<double> dis(n + 1);

    std::function<void(void)> dijkstra = [&]()
    {
        dis[s] = 1;
        for (int i = 0; i < n; i++)
        {
            int t = -1;
            for (int j = 1; j <= n; j++)
                if (!st[j] && (t == -1 || dis[j] > dis[t]))
                    t = j;

            st[t] = true;

            for (int j = 1; j <= n; j++)
                dis[j] = std::max(dis[j], dis[t] * g[t][j]);
        }
    };

    dijkstra();

    double res = 100.0 / dis[t];
    std::cout << std::fixed << std::setprecision(8) << res << '\n';
    return 0;
}