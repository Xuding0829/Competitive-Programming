#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a.begin() + 1, a.end());

    int res = 0, m = a[n];
    std::vector<int> f(m + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (f[a[i]])
            continue;
        res++;
        for (int j = a[i]; j <= m; j++)
            f[j] += f[j - a[i]];
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