#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    i64 res = 0;
    for (int i = 5; i <= n; i *= 5)
        res += (n / i);
    std::cout << res << '\n';

    return 0;
}