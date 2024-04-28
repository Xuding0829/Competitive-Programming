#include <bits/stdc++.h>

using i64 = long long;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    i64 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 a, b, c, k;
    while (std::cin >> a >> b >> c >> k, a || b || c || k)
    {
        i64 tmp = 1ll << k, x, y;

        i64 gcd = exgcd(c, tmp, x, y);

        if ((b - a) % gcd)
            std::cout << "FOREVER\n";
        else
        {
            x *= (b - a) / gcd;
            tmp /= gcd;
            std::cout << ((x % tmp) + tmp) % tmp << '\n';
        }
    }

    return 0;
}