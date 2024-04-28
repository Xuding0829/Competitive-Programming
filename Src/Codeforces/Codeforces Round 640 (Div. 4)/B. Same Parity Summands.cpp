#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    i64 n, m;
    std::cin >> n >> m;

    i64 rest1 = n - m + 1, rest2 = n - 2 * m + 2;
    if (rest1 % 2 == 1 && rest1 > 0)
    {
        std::cout << "YES\n";
        for (int i = 0; i < m - 1; i++)
            std::cout << 1 << ' ';
        std::cout << rest1 << '\n';
    }
    else if (rest2 % 2 == 0 && rest2 > 0)
    {
        std::cout << "YES\n";
        for (int i = 0; i < m - 1; i++)
            std::cout << 2 << ' ';
        std::cout << rest2 << '\n';
    }
    else
    {
        std::cout << "NO\n";
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
