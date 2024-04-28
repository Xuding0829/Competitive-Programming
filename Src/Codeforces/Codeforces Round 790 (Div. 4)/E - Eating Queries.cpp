#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n), s(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end(), std::greater<>());

    s[0] = a[0];
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i];

    while (q--)
    {
        int m;
        std::cin >> m;

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (s[mid] >= m)
                r = mid;
            else
                l = mid + 1;
        }

        if (s[l] >= m)
            std::cout << l + 1 << '\n';
        else
            std::cout << -1 << '\n';
    }
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