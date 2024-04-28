#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i];

    std::vector<int> f(m + 1);
    std::vector<int> g(m + 1);
    g[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
        {
            int cnt = 0, maxv = std::max(f[j], f[j - v[i]] + w[i]);
            if (maxv == f[j])
                (cnt += g[j]) %= mod;
            if (maxv == f[j - v[i]] + w[i])
                (cnt += g[j - v[i]]) %= mod;
            f[j] = maxv, g[j] = cnt;
        }

    int cnt = 0;
    for (int i = 0; i <= m; i++)
        if (f[m] == f[i])
            (cnt += g[i]) %= mod;
    std::cout << cnt << '\n';

    return 0;
}