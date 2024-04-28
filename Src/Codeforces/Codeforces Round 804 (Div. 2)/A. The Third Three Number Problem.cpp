#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n & 1)
        std::cout << "-1\n";
    else
        std::cout << 0 << ' ' << n / 2 << ' ' << n / 2 << '\n';
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