#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    bool flag = false;
    int res = 0, cnt1 = 0, cnt2 = 0;
    int u1 = 0, u2 = 0;
    for (int i = 0, j = n - 1;;)
    {
        if (j < i)
            break;

        u1 = 0;
        while (i <= j && u1 <= u2)
            cnt1 += a[i], u1 += a[i], i++, flag = true;

        if (flag)
            res++, flag = false;

        if (j < i)
            break;

        u2 = 0;
        while (i <= j && u2 <= u1)
            cnt2 += a[j], u2 += a[j], j--, flag = true;

        if (flag)
            res++, flag = false;
    }

    std::cout << res << ' ' << cnt1 << ' ' << cnt2 << '\n';
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