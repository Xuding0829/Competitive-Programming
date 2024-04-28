#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    a = std::ceil(c * 1.0 / 2) + a;
    b = c / 2 + b;
    if (a > b)
        std::cout << "First\n";
    else
        std::cout << "Second\n";
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