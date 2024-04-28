#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector g(n, std::vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> g[i][j];

    int res = 0;
    std::vector vis(n, std::vector<bool>(m));
    auto bfs = [&](int i, int j) -> void
    {
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int a = x - 1; a <= x + 1; a++)
            {
                for (int b = y - 1; b <= y + 1; b++)
                {
                    if (a == x && b == y)
                        continue;
                    if (a < 0 || a >= n || b < 0 || b >= m)
                        continue;
                    if (vis[a][b])
                        continue;
                    if (g[a][b] == 'W')
                        q.push({a, b}), vis[a][b] = true;
                }
            }
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && g[i][j] == 'W')
                bfs(i, j), res++;
    std::cout << res << '\n';

    return 0;
}