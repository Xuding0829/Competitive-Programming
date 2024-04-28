#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int f[35][35][55];

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::cout << f[n][m][k] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(f, 0x3f, sizeof(f));

    for (int i = 0; i <= 30; i++)
        for (int j = 0; j <= 30; j++)
        {
            f[i][j][0] = 0;
            if (i * j <= 50)
                f[i][j][i * j] = 0;
        }

    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            for (int k = 1; k <= std::min(50, i * j); k++)
            {
                for (int t = 1; t < i; t++)
                {
                    f[i][j][k] = std::min(f[i - t][j][k] + j * j, f[i][j][k]);
                    if (k > t * j)
                        f[i][j][k] = std::min(f[i][j][k], f[i - t][j][k - t * j] + j * j);
                }
                for (int t = 1; t < j; t++)
                {
                    f[i][j][k] = std::min(f[i][j - t][k] + i * i, f[i][j][k]);
                    if (k > t * i)
                        f[i][j][k] = std::min(f[i][j][k], f[i][j - t][k - t * i] + i * i);
                }
            }
        }
    }

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}