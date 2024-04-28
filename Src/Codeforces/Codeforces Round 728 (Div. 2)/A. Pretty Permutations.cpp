#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n % 2 == 0)
        for (int i = 1; i <= n; i += 2)
            std::cout << i + 1 << ' ' << i << ' ';
    else
    {
        for (int i = 1; i < n - 2; i += 2)
            std::cout << i + 1 << ' ' << i << ' ';
        std::cout << n - 1 << ' ' << n << ' ' << n - 2;
    }

    std::cout << '\n';
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