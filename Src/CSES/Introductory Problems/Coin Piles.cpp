#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;

    if ((a + b) % 3 != 0 || a > 2 * b || b > 2 * a)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
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