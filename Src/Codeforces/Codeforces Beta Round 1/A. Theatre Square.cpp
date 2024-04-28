#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m, a;
    std::cin >> n >> m >> a;

    i64 x, y;
    x = (n + a - 1) / a;
    y = (m + a - 1) / a;

    i64 res = x * y;
    std::cout << res << '\n';

    return 0;
}