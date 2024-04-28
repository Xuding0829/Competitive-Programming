#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<i64> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % m;

    i64 res = 0;
    for (int i = 1; i <= n; i++)
        (res += (n - i + 1) * (f[i] * f[n - i + 1] % m)) %= m;
    std::cout << res << '\n';
    return 0;
}