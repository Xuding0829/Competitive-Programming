#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector g(n, std::vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> g[i][j];

    std::vector dis(n + 1, std::vector<int>(m + 1, 0x3f3f3f3f));
    std::vector vis(n + 1, std::vector<bool>(m + 1));
    auto bfs = [&]()
    {
        char cs[] = "\\/\\/";
        int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
        int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};
        std::deque<std::pair<int, int>> q;
        q.push_back({0, 0});
        dis[0][0] = 0;
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop_front();

            if (x == n && y == m)
                return dis[x][y];
            if (vis[x][y])
                continue;
            vis[x][y] = true;

            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a > n || b < 0 || b > m)
                    continue;
                int ga = x + ix[i], gb = y + iy[i];
                int w = (g[ga][gb] != cs[i]);
                int d = w + dis[x][y];
                if (d < dis[a][b])
                {
                    dis[a][b] = d;
                    if (w)
                        q.push_back({a, b});
                    else
                        q.push_front({a, b});
                }
            }
        }
        return -1;
    };

    if (n + m & 1)
        std::cout << "NO SOLUTION\n";
    else
        std::cout << bfs() << '\n';
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