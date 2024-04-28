#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int x, y;
    std::cin >> x >> y;

    if (x > y)
        std::cout << "0 0\n";
    else if (y % x)
        std::cout << "0 0\n";
    else
        std::cout << 1 << ' ' << y / x << '\n';
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