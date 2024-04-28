#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;

    int res = 0;
    std::vector vis(n, std::vector<bool>(m));
    vis[x][y] = true;

    std::function<void(int, int, int)> dfs = [&](int x, int y, int cnt)
    {
        if (cnt == n * m)
        {
            res++;
            return;
        }
        int dx[] = {1, -1, 2, -2, 1, -1, 2, -2}, dy[] = {2, 2, 1, 1, -2, -2, -1, -1};
        for (int i = 0; i < 8; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if (vis[a][b])
                continue;
            vis[a][b] = true;
            dfs(a, b, cnt + 1);
            vis[a][b] = false;
        }
    };

    dfs(x, y, 1);
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