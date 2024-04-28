#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    if (n == 1 && m == 1)
        std::cout << "0\n";
    else
    {
        if (n < m)
            std::swap(n, m);
        std::cout << n + 2 * (m - 1) << '\n';
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