#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    std::cin >> n >> t;

    std::vector g(n, std::vector<bool>(n));
    std::vector vis(n, std::vector<bool>(n));
    std::vector match(n, std::vector<std::pair<int, int>>(n, {-1, -1}));

    while (t--)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u][v] = true;
    }

    std::function<bool(int, int)> find = [&](int x, int y) -> bool
    {
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n || g[tx][ty] || vis[tx][ty])
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
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 && !g[i][j])
            {
                for (int k = 0; k < n; k++)
                    for (int p = 0; p < n; p++)
                        vis[k][p] = false;
                if (find(i, j))
                    res++;
            }
        }
    }
    std::cout << res << '\n';
    return 0;
}