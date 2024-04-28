#include <bits/stdc++.h>

using i64 = long long;
const int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, -inf));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            std::cin >> a[i][j];

    // std::fill(f.begin(), f.end(), -0x3f);
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = std::max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);

    int res = -inf;
    for (int i = 1; i <= n; i++)
        res = std::max(res, f[n][i]);
    std::cout << res << '\n';
    return 0;
}