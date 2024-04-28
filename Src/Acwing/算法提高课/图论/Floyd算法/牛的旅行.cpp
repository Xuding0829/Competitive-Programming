#include <bits/stdc++.h>

using i64 = long long;

constexpr double inf = 1e20;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::pair<int, int> q[n];
    for (int i = 0; i < n; i++)
        std::cin >> q[i].first >> q[i].second;

    std::vector g(n, std::vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> g[i][j];

    auto get_dis = [&](std::pair<int, int> a, std::pair<int, int> b)
    {
        double x = a.first - b.first, y = a.second - b.second;
        return sqrt(x * x + y * y);
    };

    std::vector dis(n, std::vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '0')
                dis[i][j] = inf;
            else
                dis[i][j] = get_dis(q[i], q[j]);
        }
    }
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

    double res1 = 0;
    std::vector<double> maxn(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dis[i][j] != inf)
            {
                maxn[i] = std::max(maxn[i], dis[i][j]);
                res1 = std::max(res1, maxn[i]);
            }

    double res2 = inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (dis[i][j] == inf)
                res2 = std::min(res2, maxn[i] + get_dis(q[i], q[j]) + maxn[j]);
        }

    // auto findMax = [&](int x, int y)
    // {
    //     double res = 0;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (dis[i][x] <= inf / 2 || dis[i][y] <= inf / 2)
    //             res = std::max(res, maxn[i]);
    //     }
    //     return res;
    // };

    std::cout << std::fixed << std::setprecision(6) << std::max(res1, res2) << '\n';
    return 0;
}
