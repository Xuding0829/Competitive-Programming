#include <bits/stdc++.h>

using i64 = long long;

const int N = 55;
int w[N][N];
int f[N * 2][N][N];

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
        for (int i = std::max(1, k - m); i <= std::min(k - 1, n); i++)
            for (int j = std::max(1, k - m); j <= std::min(k - 1, n); j++)
            {

                int t = w[i][k - i];
                if (i != j)
                    t += w[j][k - j];

                int &x = f[k][i][j];
                x = std::max(x, f[k - 1][i - 1][j - 1] + t);
                x = std::max(x, f[k - 1][i - 1][j] + t);
                x = std::max(x, f[k - 1][i][j - 1] + t);
                x = std::max(x, f[k - 1][i][j] + t);
            }
    std::cout << f[n + m][n][n] << '\n';

    return 0;
}