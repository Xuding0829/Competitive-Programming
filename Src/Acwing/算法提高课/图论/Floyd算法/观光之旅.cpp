#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector g(n, std::vector<int>(n, inf));
    for (int i = 0; i < n; i++)
        g[i][i] = 0;
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u][v] = g[v][u] = std::min(g[u][v], w);
    }

    std::vector d(g);
    std::vector pos(n, std::vector<int>(n, -1));
    // for (int k = 0; k < n; k++)

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         std::cout << pos[i][j] << " \n"[j == n - 1];

    std::vector<int> path;
    std::function<void(int, int)> get_path = [&](int i, int j)
    {
        if (pos[i][j] == -1)
            return;
        int tmp = pos[i][j];
        get_path(i, tmp);
        path.push_back(tmp);
        get_path(tmp, j);
    };

    i64 res = inf;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < i; j++)
                if ((i64)d[i][j] + g[i][k] + g[k][j] < res)
                {
                    res = d[i][j] + g[i][k] + g[k][j];
                    path.clear();
                    path.push_back(k);
                    path.push_back(i);
                    get_path(i, j);
                    path.push_back(j);
                }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j], pos[i][j] = k;
    }

    if (res == inf)
        std::cout << "No solution.\n";
    else
        for (auto x : path)
            std::cout << x + 1 << ' ';

    return 0;
}