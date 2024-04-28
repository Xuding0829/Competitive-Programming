#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, a, b;
    std::cin >> n >> a >> b;

    std::vector<i64> x(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> x[i], d[i] = x[i] - x[i - 1];

    //  for (auto i : d)
    //      std::cout << i << '\n';
    //  std::cout << '\n';

    i64 res = 0;
    for (int i = 2; i <= n; i++)
        res += std::min(d[i] * a, b);

    std::cout << res << '\n';
    return 0;
}