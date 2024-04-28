#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    int l = n, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            l = std::min(l, i), r = std::max(r, i);
    }

    while (true)
    {
        if (b[l - 1] <= b[l])
            l--;
        else
            break;
    }

    while (true)
    {
        if (b[r + 1] >= b[r])
            r++;
        else
            break;
    }
    std::cout << std::max(1, l + 1) << ' ' << std::min(r + 1, n) << '\n';
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