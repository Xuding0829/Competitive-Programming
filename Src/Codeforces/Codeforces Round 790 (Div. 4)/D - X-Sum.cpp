#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

    auto search = [&](int x, int y)
    {
        int u = x, v = y;
        int res = a[x][y];

        while (x - 1 >= 0 && y - 1 >= 0)
            res += a[--x][--y];

        x = u, y = v;
        while (x - 1 >= 0 && y + 1 < m)
            res += a[--x][++y];

        x = u, y = v;
        while (x + 1 < n && y - 1 >= 0)
            res += a[++x][--y];

        x = u, y = v;
        while (x + 1 < n && y + 1 < m)
            res += a[++x][++y];

        return res;
    };

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = std::max(res, search(i, j));
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