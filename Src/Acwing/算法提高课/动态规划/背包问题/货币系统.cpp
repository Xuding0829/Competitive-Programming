#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i];

    std::vector<i64> f(m + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] += f[j - v[i]];

    std::cout << f[m] << '\n';
    return 0;
}