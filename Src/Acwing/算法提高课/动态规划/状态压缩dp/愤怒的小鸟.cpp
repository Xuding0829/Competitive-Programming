#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1e-6;
constexpr int inf = 0x3f3f3f3f;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<double, double>> pos(n);
    for (int i = 0; i < n; i++)
        std::cin >> pos[i].first >> pos[i].second;

    std::vector g(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        g[i][i] = 1 << i;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            double a = (pos[j].first * pos[i].second - pos[i].first * pos[j].second) / (pos[i].first * pos[j].first * (pos[i].first - pos[j].first));
            double b = (pos[i].second / pos[i].first) - a * pos[i].first;

            if (a >= 0)
                continue;

            for (int k = 0; k < n; k++)
            {
                if (std::fabs(a * pos[k].first * pos[k].first + b * pos[k].first - pos[k].second) <= eps)
                    g[i][j] |= 1 << k;
            }
        }
    }

    std::vector<int> f(1 << 18, inf);
    f[0] = 0;
    for (int i = 0; i < 1 << n; i++)
    {
        int tmp;
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
                continue;
            tmp = j;
            break;
        }

        for (int k = 0; k < n; k++)
            f[i | g[tmp][k]] = std::min(f[i | g[tmp][k]], f[i] + 1);
    }
    std::cout << f[(1 << n) - 1] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}