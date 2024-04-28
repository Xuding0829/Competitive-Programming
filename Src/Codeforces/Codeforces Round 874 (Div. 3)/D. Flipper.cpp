#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    int pos = std::find(a.begin(), a.end(), n) - a.begin();
    if (pos == 1)
        pos = std::find(a.begin(), a.end(), n - 1) - a.begin();

    int r = pos == n ? pos : pos - 1;
    auto get = [&](int l, int r)
    {
        std::vector<int> res;
        for (int i = r + 1; i <= n; i++)
            res.push_back(a[i]);
        for (int i = r; i >= l; i--)
            res.push_back(a[i]);
        for (int i = 1; i <= l - 1; i++)
            res.push_back(a[i]);
        return res;
    };

    std::vector<int> ans(n, 1);
    for (int l = 1; l <= r; l++)
        ans = std::max(ans, get(l, r));

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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