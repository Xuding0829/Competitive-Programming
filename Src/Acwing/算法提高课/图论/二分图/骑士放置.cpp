#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, t;
    std::cin >> n >> m >> t;

    std::vector g(n, std::vector<bool>(m));
    std::vector vis(n, std::vector<bool>(m));
    std::vector match(n, std::vector<std::pair<int, int>>(m, {-1, -1}));
    for (int i = 0; i < t; i++)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g[x][y] = true;
    }

    std::function<bool(int, int)> find = [&](int x, int y) -> bool
    {
        int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
        int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
        for (int i = 0; i < 8; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || g[tx][ty] || vis[tx][ty])
                continue;
            vis[tx][ty] = true;
            auto [u, v] = match[tx][ty];
            if (u == -1 || find(u, v))
            {
                match[tx][ty] = {x, y};
                return true;
            }
        }
        return false;
    };

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 == 0 && !g[i][j])
            {
                for (int k = 0; k < n; k++)
                    for (int p = 0; p < m; p++)
                        vis[k][p] = false;
                if (find(i, j))
                    res++;
            }
        }
    }
    std::cout << n * m - t - res << '\n';
    return 0;
}