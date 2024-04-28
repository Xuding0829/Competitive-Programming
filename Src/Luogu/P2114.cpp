#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<std::string, int>> a(n);
    for (int i = 0, x; i < n; i++)
    {
        std::string op;
        std::cin >> op >> x;
        a[i] = {op, x};
    }

    auto get = [&](int bit, int now)
    {
        for (int i = 0; i < n; i++)
        {
            auto [s, t] = a[i];
            int tmp = t >> bit & 1;
            if (s == "AND")
                now &= tmp;
            else if (s == "OR")
                now |= tmp;
            else
                now ^= tmp;
        }
        return now;
    };

    int res = 0, val = 0;
    for (int bit = 29; bit >= 0; bit--)
    {
        int x1 = get(bit, 0);
        int x2 = get(bit, 1);

        if (val + (1 << bit) <= m && x1 < x2)
            val += (1 << bit), res += (x2 << bit);
        else
            res += (x1 << bit);
    }
    std::cout << res << '\n';

    return 0;
}