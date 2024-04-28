#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    i64 sum = 0;
    for (int i = 1, x; i < n; i++)
        std::cin >> x, sum += x;

    std::cout << (1 + n) * n / 2 - sum << '\n';

    return 0;
}