#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;

    i64 res = 0;
    if (n * 2 <= m)
        res = n + (m - 2 * n) / 4;
    else
        res = m / 2;

    std::cout << res << '\n';

    return 0;
}