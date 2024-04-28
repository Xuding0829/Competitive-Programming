#include <bits/stdc++.h>

using i64 = long long;

int f[110][20][20];
int w[20][20];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int x, y, z;
    while (std::cin >> x >> y >> z, x || y || z)
        w[x][y] = z;

    for (int k = 2; k <= n + n; k++)
    {
        for (int i1 = 1; i1 <= n; i1++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                if (i1 <= n && i1 >= 1 && i2 <= n && i2 >= 1)
                {
                    int &x = f[k][i1][i2];
                    int t = w[i1][j1];
                    if (i1 != i2)
                        t += w[i2][j2];
                    x = std::max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = std::max(x, f[k - 1][i1][i2 - 1] + t);
                    x = std::max(x, f[k - 1][i1 - 1][i2] + t);
                    x = std::max(x, f[k - 1][i1][i2] + t);
                }
            }
        }
    }

    std::cout << f[2 * n][n][n] << '\n';

    return 0;
}