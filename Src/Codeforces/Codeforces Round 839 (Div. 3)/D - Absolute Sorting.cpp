#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int l = 0, r = 1e9;
    for (int i = 0; i < n - 1; i++)
    {
        int x = a[i], y = a[i + 1];
        if (x < y)
            r = std::min(r, (x + y) >> 1);
        if (x > y)
            l = std::max(l, (x + y + 1) >> 1);
    }

    if (l <= r)
        std::cout << l << '\n';
    else
        std::cout << -1 << '\n';
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