#include <bits/stdc++.h>

using i64 = long long;

const int N = 50, inf = 0x3f3f3f;
int f[N][10 * N][10 * N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, ma, mb;
    std::cin >> n >> ma >> mb;

    std::vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i] >> b[i] >> c[i];

    memset(f, 0x3f, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 400; j++)
            for (int k = 0; k <= 400; k++)
            {
                if (a[i] > j || b[i] > k)
                    f[i][j][k] = f[i - 1][j][k];
                else
                    f[i][j][k] = std::min(f[i - 1][j][k], f[i - 1][j - a[i]][k - b[i]] + c[i]);
            }

    int res = inf;
    for (int i = 1; i <= 400; i++)
        for (int j = 1; j <= 400; j++)
            if (j * ma == i * mb)
                res = std::min(res, f[n][i][j]);

    if (res == inf)
        res = -1;
    std::cout << res << '\n';

    return 0;
}