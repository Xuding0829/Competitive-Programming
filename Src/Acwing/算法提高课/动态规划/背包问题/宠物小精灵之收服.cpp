#pragma GCC optimize(2)
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t, m;
    std::cin >> n >> t >> m;

    std::vector<int> v1(m + 1), v2(m + 1);
    for (int i = 1; i <= m; i++)
        std::cin >> v1[i] >> v2[i];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(t + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= v1[i]; j--)
            for (int k = t - 1; k >= v2[i]; k--)
                f[j][k] = std::max(f[j][k], f[j - v1[i]][k - v2[i]] + 1);
    std::cout << f[n][t - 1] << ' ';

    int cost_health = t;
    for (int k = 0; k < t; k++)
        if (f[n][k] == f[n][t - 1])
            cost_health = std::min(cost_health, k);
    std::cout << t - cost_health << '\n';

    return 0;
}