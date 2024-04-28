#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    i64 sum = 0, maxn = 0;
    for (i64 i = 0, x; i < n; i++)
    {
        std::cin >> x;
        maxn = std::max(maxn, x);
        sum += maxn - x;
    }
    std::cout << sum << '\n';
    return 0;
}