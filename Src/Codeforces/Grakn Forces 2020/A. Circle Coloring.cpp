#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    std::vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        if (!i)
            res[i] = a[i];
        else if (a[i] != res[i - 1] && (i + 1 < n || a[i] != res[0]))
            res[i] = a[i];
        else if (b[i] != res[i - 1] && (i + 1 < n || b[i] != res[0]))
            res[i] = b[i];
        else
            res[i] = c[i];
    }

    for (int i = 0; i < n; i++)
        std::cout << res[i] << " \n"[i == n - 1];
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