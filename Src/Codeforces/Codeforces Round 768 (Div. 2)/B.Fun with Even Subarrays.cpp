#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int res = 0, val = a[n - 1], ed = n - 1;
    i64 d = 0;
    while (1)
    {
        while (ed - d >= 0 && a[ed - d] == val)
            d++;
        if (ed - d < 0)
            break;
        res++;
        d <<= 1;
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