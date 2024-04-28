#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], a[i] += a[i - 1];

    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (a[mid] - a[i - 1] <= k)
                l = mid;
            else
                r = mid - 1;
        }
        if (a[l] - a[i - 1] == k)
            res = std::min(res, n - (l - i + 1));
    }
    std::cout << (res < 0x3f3f3f3f ? res : -1) << '\n';
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