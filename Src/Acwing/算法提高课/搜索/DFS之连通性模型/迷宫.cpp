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

    int sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;

    if (g[sx][sy] == '#' || g[ex][ey] == '#')
    {
        std::cout << "NO\n";
        return;
    }

    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    std::vector vis(n, std::vector<bool>(n));
    std::function<bool(int, int)> dfs = [&](int x, int y)
    {
        if (x == ex && y == ey)
            return true;

        vis[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= n)
                continue;
            if (g[a][b] == '#' || vis[a][b])
                continue;
            if (dfs(a, b))
                return true;
        }
        return false;
    };
    std::cout << (dfs(sx, sy) ? "YES\n" : "NO\n");
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