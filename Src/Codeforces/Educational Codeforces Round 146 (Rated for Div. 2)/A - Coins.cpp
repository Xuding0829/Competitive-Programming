#include <bits/stdc++.h>

using i64 = long long;

i64 gcd(i64 a, i64 b)
{
    return (b ? gcd(b, a % b) : a);
}

void solve()
{
    i64 n, k;
    std::cin >> n >> k;

    i64 d = gcd(2, k);
    if (n % d == 0)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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