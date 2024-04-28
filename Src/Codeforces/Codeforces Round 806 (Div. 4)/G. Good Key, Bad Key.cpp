#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
constexpr int N = 2e5 + 10;

i64 f[N][50];
i64 g[50];

void get()
{
    g[0] = 1;
    for (int i = 1; i <= 34; i++)
        g[i] = g[i - 1] * 2;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 32; j++)
            f[i][j] = -inf;
    // f[i, j] 表示 前i个箱子使用j把坏钥匙
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i, 32); j++)
        {
            f[i][j] = std::max(f[i][j], f[i - 1][j] + (i64)a[i] / g[j] - k); // 使用好钥匙
            if (j)
                f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + (i64)a[i] / g[j]); // 使用坏钥匙
            if (j >= 31)
                f[i][j] = std::max(f[i][j], f[i - 1][j]);
        }
    }

    i64 res = 0;
    for (int i = 0; i < 40; i++)
        res = std::max(res, f[n][i]);
    std::cout << res << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    get();

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}