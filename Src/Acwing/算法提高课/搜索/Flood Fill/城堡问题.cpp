#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector g(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> g[i][j];

    int res = 0, area = 0;
    std::vector vis(n, std::vector<bool>(m));
    auto bfs = [&](int i, int j)
    {
        int cnt = 0;
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            cnt++;

            for (int k = 0; k < 4; k++)
            {
                if (g[x][y] >> k & 1)
                    continue;
                int a = x + dx[k], b = y + dy[k];
                if (vis[a][b])
                    continue;
                q.push({a, b});
                vis[a][b] = true;
            }
        }
        return cnt;
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j])
                res++, area = std::max(area, bfs(i, j));

    std::cout << res << '\n'
              << area << '\n';

    return 0;
}