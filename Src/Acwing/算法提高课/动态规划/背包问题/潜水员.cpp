#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, inf));
    f[0][0] = 0;
    while (k--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        for (int i = n; i >= 0; i--)
            for (int j = m; j >= 0; j--)
                f[i][j] = std::min(f[i][j], f[std::max(0, i - a)][std::max(0, j - b)] + c);
    }
    std::cout << f[n][m] << '\n';

    return 0;
}