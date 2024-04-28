#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if ((a - b) * (c - d) > 0 && (a - c) * (b - d) > 0)
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