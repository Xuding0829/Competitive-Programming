#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int x, k;
    std::cin >> x >> k;

    if (x % k)
    {
        std::cout << 1 << '\n';
        std::cout << x << '\n';
    }

    else
    {
        std::cout << 2 << '\n';
        std::cout << 1 << ' ' << x - 1 << '\n';
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