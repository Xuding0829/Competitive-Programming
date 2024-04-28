#include <bits/stdc++.h>

using i64 = long long;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 res = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < (1 << n); i++)
    {
        i64 x = 0, y = 0;
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
                x += a[j];
            else
                y += a[j];
        }
        res = std::min(res, std::abs(x - y));
    }
    std::cout << res << '\n';
    return 0;
}
