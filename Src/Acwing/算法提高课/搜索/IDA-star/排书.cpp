#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int dep = 0;
    auto f = [&]()
    {
        int res = 0;
        for (int i = 0; i + 1 < n; i++)
            if (a[i] + 1 != a[i + 1])
                res++;
        return (res + 2) / 3;
    };

    auto check = [&]()
    {
        for (int i = 0; i < n; i++)
            if (a[i] != i + 1)
                return false;
        return true;
    };

    std::function<bool(int, int)> dfs = [&](int u, int dep)
    {
        if (u + f() > dep)
            return false;
        if (check())
            return true;

        for (int len = 1; len <= n; len++)
        {
            for (int l = 0; l + len - 1 < n; l++)
            {
                int r = l + len - 1;
                for (int k = r + 1; k < n; k++)
                {
                    std::vector<int> tmp(a);
                    int x, y;
                    for (x = r + 1, y = l; x <= k; x++, y++)
                        a[y] = tmp[x];
                    for (x = l; x <= r; x++, y++)
                        a[y] = tmp[x];

                    if (dfs(u + 1, dep))
                        return true;
                    a = tmp;
                }
            }
        }
        return false;
    };

    while (dep < 5 && !dfs(0, dep))
        dep++;

    if (dep >= 5)
        std::cout << "5 or more\n";
    else
        std::cout << dep << '\n';
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