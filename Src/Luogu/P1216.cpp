#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::vector<std::vector<int>> a(t + 1, std::vector<int>(t + 1));
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= i; j++)
            std::cin >> a[i][j];

    std::vector<std::vector<int>> f(t + 1, std::vector<int>(t + 1));
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = std::max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];

    int res = 0;
    for (int i = 1; i <= t; i++)
        res = std::max(res, f[t][i]);
    std::cout << res << '\n';
    return 0;
}