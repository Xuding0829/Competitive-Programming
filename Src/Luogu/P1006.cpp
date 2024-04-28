#include <bits/stdc++.h>

using i64 = long long;

int f[10000][100][100];
int w[100][100];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> w[i][j];

    for (int k = 2; k <= n + m; k++)
        for (int i1 = 1; i1 <= n && i1 <= k; i1++)
            for (int i2 = 1; i2 <= n && i2 <= k; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                int &x = f[k][i1][i2];

                int t = w[i1][j1];
                if (i1 != i2)
                    t += w[i2][j2];

                x = std::max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                x = std::max(x, f[k - 1][i1 - 1][i2] + t);
                x = std::max(x, f[k - 1][i1][i2 - 1] + t);
                x = std::max(x, f[k - 1][i1][i2] + t);
            }
    std::cout << f[n + m][n][n] << '\n';

    return 0;
}