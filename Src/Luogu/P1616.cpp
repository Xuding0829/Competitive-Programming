#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> m >> n;

    std::vector<i64> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i];

    std::vector<i64> f(m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);
    std::cout << f[m] << '\n';

    return 0;
}