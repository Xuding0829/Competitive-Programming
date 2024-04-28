#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;

    i64 l = 0, r = 0;
    std::vector<i64> tr(n);
    for (int i = 0; i < n; i++)
        std::cin >> tr[i], r = std::max(r, tr[i]);

    auto check = [&](int k)
    {
        i64 res = 0;
        for (int i = 0; i < n; i++)
        {
            if (tr[i] > k)
                res += tr[i] - k;
        }
        return res >= m;
    };

    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    std::cout << l << '\n';

    return 0;
}