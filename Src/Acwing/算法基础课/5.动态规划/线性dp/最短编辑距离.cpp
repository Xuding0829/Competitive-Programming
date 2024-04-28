#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::string a, b;
    std::cin >> n >> a >> m >> b;

    a = ' ' + a;
    b = ' ' + b;

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int i = 0; i <= m; i++)
        f[0][i] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = 1 + std::min(f[i - 1][j], std::min(f[i][j - 1], f[i - 1][j - 1]));
        }

    std::cout << f[n][m] << '\n';

    return 0;
}