#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), s(n + 1);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], s[i + 1] = s[i] + a[i];

    std::vector<bool> mp(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j <= n; j++)
            if (s[j] - s[i] <= n)
                mp[s[j] - s[i]] = true;

    int res = 0;
    for (int i = 0; i < n; i++)
        if (mp[a[i]])
            res++;
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