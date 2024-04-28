#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(k, INT_MIN));
    f[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        for (int j = 0; j < k; j++)
            f[i][j] = std::max(f[i - 1][j], f[i - 1][(j + k - x % k) % k] + x);
    }

    std::cout << f[n][0] << '\n';
    return 0;
}