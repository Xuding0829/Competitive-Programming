#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++)
        std::cin >> t[i];

    std::vector dis(n, std::vector<int>(n, inf));
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;

    std::function<void(int)> floyd = [&](int k)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = dis[j][i] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
    };

    int q, now = 0;
    std::cin >> q;
    while (q--)
    {
        int x, y, z;
        std::cin >> x >> y >> z;

        while (t[now] <= z && now < n)
            floyd(now++);

        if (t[x] > z || t[y] > z || dis[x][y] == inf)
            std::cout << "-1\n";
        else
            std::cout << dis[x][y] << '\n';
    }

    return 0;
}