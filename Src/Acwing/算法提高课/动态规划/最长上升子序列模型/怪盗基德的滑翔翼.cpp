#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    // 正向求LIS
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = std::max(f[i], f[j] + 1);
    }
    for (int i = 1; i <= n; i++)
        res = std::max(res, f[i]);

    // 反向求解LIS
    std::reverse(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = std::max(f[i], f[j] + 1);
    }
    for (int i = 1; i <= n; i++)
        res = std::max(res, f[i]);

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