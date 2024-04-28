#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> m >> n, n)
    {
        int sx, sy;
        std::vector g(n, std::vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                std::cin >> g[i][j];
                if (g[i][j] == '@')
                    sx = i, sy = j;
            }

        std::vector vis(n, std::vector<bool>(m));
        std::function<int(int, int)> dfs = [&](int x, int y)
        {
            int cnt = 1;
            vis[x][y] = true;
            int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m)
                    continue;
                if (g[a][b] == '#' || vis[a][b])
                    continue;
                cnt += dfs(a, b);
            }
            return cnt;
        };

        std::cout << dfs(sx, sy) << '\n';
    }

    return 0;
}