#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);

    i64 ans = 0;
    for (int len = 1; len <= n; len++)
    {
        i64 res = 0, tmp = 0;
        for (int i = 0; i < n - len; i++)
            res += a[i] * (i + 1), tmp = std::max(tmp, 1LL * a[i] * (i + 1));
        for (int i = n - len, j = n; i < n; i++, j--)
            res += a[i] * j, tmp = std::max(tmp, 1LL * a[i] * j);
        res -= tmp;
        ans = std::max(ans, res);
    }
    std::cout << ans << '\n';
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