#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    auto cal = [=](int n, int m)
    {
        i64 x1 = floor(m / 3.0), y1 = ceil(m / 3.0);
        i64 x2 = floor(n / 3.0), y2 = ceil(n / 3.0);
        return std::min(n * (y1 - x1), m * (y2 - x2));
    };

    auto cal2 = [=](int n, int m)
    {
        i64 res = 1e18;
        for (i64 i = 1; i < n; i++)
        {
            i64 sa = i * m, sb = (n - i) * floor(m / 2.0), sc = (n - i) * ceil(m / 2.0);
            i64 mx = std::max(sa, std::max(sb, sc)), mn = std::min(sa, std::min(sb, sc));
            res = std::min(res, mx - mn);
        }
        for (i64 i = 1; i < m; i++)
        {
            i64 sa = i * n, sb = (m - i) * floor(n / 2.0), sc = (m - i) * ceil(n / 2.0);
            i64 mx = std::max(sa, std::max(sb, sc)), mn = std::min(sa, std::min(sb, sc));
            res = std::min(res, mx - mn);
        }
        return res;
    };

    i64 res = std::min(cal(n, m), cal2(n, m));
    std::cout << res << '\n';

    return 0;
}