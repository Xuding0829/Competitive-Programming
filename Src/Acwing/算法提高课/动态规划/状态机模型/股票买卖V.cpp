#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> w[i];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(3));
    f[0][0] = f[0][1] = -inf;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = std::max(f[i - 1][0], f[i - 1][2] - w[i]);
        f[i][1] = f[i - 1][0] + w[i];
        f[i][2] = std::max(f[i - 1][1], f[i - 1][2]);
    }
    std::cout << std::max(f[n][1], f[n][2]) << '\n';

    return 0;
}