#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int l, r, x;
    std::cin >> l >> r >> x;

    int a, b;
    std::cin >> a >> b;

    if (a == b)
        std::cout << "0\n";
    else if (std::abs(a - b) >= x)
        std::cout << "1\n";
    else if (std::abs(r - a) >= x && std::abs(r - b) >= x || std::abs(l - a) >= x && std::abs(l - b) >= x)
        std::cout << "2\n";
    else if (std::abs(a - l) >= x && std::abs(l - r) >= x && std::abs(r - b) >= x || std::abs(a - r) >= x && std::abs(l - r) >= x && std::abs(l - b) >= x)
        std::cout << "3\n";
    else
        std::cout << "-1\n";
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