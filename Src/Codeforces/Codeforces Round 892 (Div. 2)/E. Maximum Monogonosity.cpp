#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    std::vector dp(n + 1, std::vector<i64>(k + 1));
    std::vector f(n + 1, std::vector<i64>(4, -0x3f3f3f3f3f3f3f3f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i && j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            f[i - j][0] = std::max(f[i - j][0], dp[i - 1][j - 1] + a[i] + b[i]);
            f[i - j][1] = std::max(f[i - j][1], dp[i - 1][j - 1] + a[i] - b[i]);
            f[i - j][2] = std::max(f[i - j][2], dp[i - 1][j - 1] - a[i] + b[i]);
            f[i - j][3] = std::max(f[i - j][3], dp[i - 1][j - 1] - a[i] - b[i]);
            dp[i][j] = std::max(dp[i][j], f[i - j][0] - a[i] - b[i]);
            dp[i][j] = std::max(dp[i][j], f[i - j][1] + a[i] - b[i]);
            dp[i][j] = std::max(dp[i][j], f[i - j][2] - a[i] + b[i]);
            dp[i][j] = std::max(dp[i][j], f[i - j][3] + a[i] + b[i]);
        }
    }
    std::cout << dp[n][k] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}