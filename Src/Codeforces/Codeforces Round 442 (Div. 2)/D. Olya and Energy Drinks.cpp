#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector g(n, std::vector<char>(m));
    std::vector vis(n, std::vector<bool>(m));
    std::vector dis(n, std::vector<int>(m, inf));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> g[i][j];

    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    auto bfs = [&]() -> void
    {
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

        std::queue<std::pair<int, int>> q;
        q.push({x1, y1});
        dis[x1][y1] = 0;
        while (q.size())
        {
            int nowx = q.front().first, nowy = q.front().second;
            q.pop();

            if (vis[nowx][nowy])
                continue;
            vis[nowx][nowy] = true;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    int x = nowx + dx[i] * j, y = nowy + dy[i] * j;
                    if (x < 0 || x >= n || y < 0 || y >= m)
                        break;
                    if (vis[x][y])
                        break;

                    if (dis[x][y] <= dis[nowx][nowy])
                        break;
                    else
                        dis[x][y] = dis[nowx][nowy] + 1;

                    if (g[x][y] == '#')
                        break;

                    q.push({x, y});
                }
            }
        }
    };

    bfs();

    std::cout << (dis[x2][y2] == inf ? -1 : dis[x2][y2]);
    return 0;
}