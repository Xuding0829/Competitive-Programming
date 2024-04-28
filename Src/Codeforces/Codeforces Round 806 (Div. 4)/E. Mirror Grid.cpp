#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector g(n, std::vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> g[i][j];

    auto get = [&](int x, int y)
    {
        int x2 = y, y2 = n - 1 - x;
        int x3 = n - 1 - x, y3 = n - 1 - y;
        int x4 = n - 1 - y, y4 = x;

        int cnt = 0;
        if (g[x][y] == '1')
            cnt++;
        if (g[x2][y2] == '1')
            cnt++;
        if (g[x3][y3] == '1')
            cnt++;
        if (g[x4][y4] == '1')
            cnt++;
        return std::min(cnt, 4 - cnt);
    };

    int res = 0;
    for (int i = 0; i < (n + 1) / 2 - n % 2; i++)
        for (int j = 0; j < (n + 1) / 2; j++)
            res += get(i, j);
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