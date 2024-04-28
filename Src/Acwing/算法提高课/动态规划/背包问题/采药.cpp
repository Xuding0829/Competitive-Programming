#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(m), w(m);
    for (int i = 0; i < m; i++)
        std::cin >> v[i] >> w[i];

    std::vector<int> f(n + 1);
    for (int i = 0; i < m; i++)
        for (int j = n; j >= v[i]; j--)
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);

    std::cout << f[n] << '\n';

    return 0;
}