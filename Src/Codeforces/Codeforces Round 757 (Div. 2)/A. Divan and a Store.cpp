#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, l, r, k;
    std::cin >> n >> l >> r >> k;

    int res = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= l && a[i] <= r && k - a[i] >= 0)
            res++, k -= a[i];
    }

    std::cout << res << '\n';
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