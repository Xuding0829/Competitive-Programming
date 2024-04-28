#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    i64 n, m;
    std::cin >> n >> m;
    std::cout << (m - 1) / (n - 1) << '\n';
    // std::cout << (m - 1) / (n - 1) * n + (m - 1) % (n - 1) + 1 << '\n';
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