#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        i64 x, y;
        std::cin >> y >> x;

        i64 t = std::max(x, y) - 1; // t用于判断最大的整数平方根
        i64 res = t * t;
        if (t & 1)
        {
            if (x < y)
                res += 2 * y - x;
            else
                res += y;
        }
        else
        {
            if (x < y)
                res += x;
            else
                res += 2 * x - y;
        }
        std::cout << res << '\n';
    }

    return 0;
}