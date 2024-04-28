#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> w(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> w[i][j];

    std::vector<std::vector<i64>> f(1 << 20, std::vector<i64>(20, 0x3f3f3f));
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (i - (1 << j) >> k & 1)
                        f[i][j] = std::min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

    std::cout << f[(1 << n) - 1][n - 1] << '\n';
    return 0;
}