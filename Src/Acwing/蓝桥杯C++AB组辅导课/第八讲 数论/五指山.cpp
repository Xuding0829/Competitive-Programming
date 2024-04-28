#include <bits/stdc++.h>

using i64 = long long;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve()
{
    i64 n, d, x, y;
    std::cin >> n >> d >> x >> y;

    i64 a, b;
    int gcd = exgcd(d, n, a, b);

    if ((y - x) % gcd)
        std::cout << "Impossible\n";
    else
    {
        a *= (y - x) / gcd;
        std::cout << (a % (n / gcd) + (n / gcd)) % (n / gcd) << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}