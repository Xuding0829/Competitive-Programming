#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sum = 0;
    std::map<int, int> mp;
    for (int i = 0, x; i < 5; i++)
        std::cin >> x, mp[x]++, sum += x;

    int res = sum;
    for (auto [a, b] : mp)
    {
        if (b > 2)
            res = std::min(res, sum - 3 * a);
        if (b > 1)
            res = std::min(res, sum - 2 * a);
    }
    std::cout << res << '\n';

    return 0;
}