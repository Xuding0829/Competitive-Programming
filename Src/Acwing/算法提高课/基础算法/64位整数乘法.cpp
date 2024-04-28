#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 a, b, p;
    std::cin >> a >> b >> p;

    i64 res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % p;
        a = (a * 2) % p;
        b >>= 1;
    }
    std::cout << res << '\n';

    return 0;
}