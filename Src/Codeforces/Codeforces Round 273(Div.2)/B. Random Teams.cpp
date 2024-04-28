#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;

    i64 mx, mn;
    mx = (n - m + 1) * (n - m) / 2;
    i64 a = n / m, b = n % m;
    mn = b * (a + 1) * a / 2 + (m - b) * a * (a - 1) / 2;
    std::cout << mn << ' ' << mx;

    return 0;
}
