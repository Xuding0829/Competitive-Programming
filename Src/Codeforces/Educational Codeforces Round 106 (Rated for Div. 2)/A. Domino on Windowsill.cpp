#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k1, k2;
    std::cin >> n >> k1 >> k2;

    int w, b;
    std::cin >> w >> b;

    int cnt1 = std::min(k1, k2) + (std::max(k1, k2) - std::min(k1, k2)) / 2;
    int cnt2 = std::min(n - k1, n - k2) + (std::max(n - k1, n - k2) - std::min(n - k1, n - k2)) / 2;

    if (cnt1 < w || cnt2 < b)
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