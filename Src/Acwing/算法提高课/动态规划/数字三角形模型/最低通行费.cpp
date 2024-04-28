#include <bits/stdc++.h>

using i64 = long long;
constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> w(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> w[i][j];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, inf));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                f[i][j] = w[i][j];
            else
                f[i][j] = std::min(f[i - 1][j] + w[i][j], f[i][j - 1] + w[i][j]);
        }

    std::cout << f[n][n] << '\n';

    return 0;
}