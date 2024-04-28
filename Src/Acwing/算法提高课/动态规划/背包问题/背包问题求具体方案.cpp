#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i];

    std::vector<std::vector<int>> f(n + 2, std::vector<int>(m + 1));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i + 1][j];
            if (j >= v[i])
                f[i][j] = std::max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    }

    std::vector<int> path;
    for (int i = 1, cur_v = m; i <= n; i++)
        if (cur_v >= v[i] && f[i][cur_v] == f[i + 1][cur_v - v[i]] + w[i])
            cur_v -= v[i], path.emplace_back(i);

    for (int i = 0; i < path.size(); i++)
        std::cout << path[i] << " \n"[i == (int)path.size()];

    return 0;
}