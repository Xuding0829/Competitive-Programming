#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<i64> x(n + 1), y(m + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> x[i];
    for (int i = 1; i <= m; i++)
        std::cin >> y[i];

    i64 sx = 0, sy = 0;
    for (int i = 1; i <= n; i++)
        (sx += ((i - 1) * x[i] - (n - i) * x[i]) % mod) %= mod;
    for (int i = 1; i <= m; i++)
        (sy += ((i - 1) * y[i] - (m - i) * y[i]) % mod) %= mod;

    i64 res = (sx % mod * sy % mod) % mod;
    std::cout << res << '\n';
    return 0;
}