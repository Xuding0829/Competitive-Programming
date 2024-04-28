#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> w(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> w[i][j];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= j; k++)
                f[i][j] = std::max(f[i][j], f[i - 1][j - k] + w[i][k]);
    std::cout << f[n][m] << '\n';

    int j = m;
    std::vector<int> way(n + 1);
    for (int i = n; i; i--)
        for (int k = 0; k <= j; k++)
            if (f[i][j] == f[i - 1][j - k] + w[i][k])
            {
                way[i] = k, j -= k;
                break;
            }

    for (int i = 1; i <= n; i++)
        std::cout << i << ' ' << way[i] << "\n";

    return 0;
}