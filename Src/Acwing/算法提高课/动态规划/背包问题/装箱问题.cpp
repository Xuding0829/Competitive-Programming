#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int v, n;
    std::cin >> v >> n;

    std::vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> w[i];

    std::vector<int> f(v + 1);
    for (int i = 1; i <= n; i++)
        for (int j = v; j >= w[i]; j--)
            f[j] = std::max(f[j], f[j - w[i]] + w[i]);

    std::cout << v - f[v] << '\n';

    return 0;
}