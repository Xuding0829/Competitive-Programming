#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 110000, M = 110;

int w[N];
int f[N][M][2];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    for (int i = 1; i <= n; i++)
        std::cin >> w[i];

    memset(f, -0x3f, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            f[i][j][0] = f[i - 1][j][0];
            if (j)
                f[i][j][0] = std::max(f[i][j][0], f[i - 1][j - 1][1] + w[i]);
            f[i][j][1] = std::max(f[i - 1][j][1], f[i - 1][j][0] - w[i]);
        }
    }

    int res = 0;
    for (int i = 0; i <= k; i++)
        res = std::max(res, f[n][i][0]);
    std::cout << res << '\n';

    return 0;
}