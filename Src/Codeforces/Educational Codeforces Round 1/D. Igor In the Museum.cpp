#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector g(n + 1, std::vector<char>(m + 1));
    std::vector a(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> g[i][j];

    std::vector<int> ans(n * m + 1);

    int cnt = 0, id = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    std::vector vis(n + 1, std::vector<bool>(m + 1));

    std::function<void(int, int)> dfs = [&](int x, int y)
    {
        a[x][y] = id;
        vis[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (vis[nx][ny])
                continue;
            if (g[nx][ny] == '*')
                cnt++;
            else
                dfs(nx, ny);
        }
    };

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '.' && !vis[i][j])
            {
                cnt = 0;
                dfs(i, j);
                ans[id++] = cnt;
            }
        }

    while (k--)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << ans[a[x][y]] << '\n';
    }

    return 0;
}