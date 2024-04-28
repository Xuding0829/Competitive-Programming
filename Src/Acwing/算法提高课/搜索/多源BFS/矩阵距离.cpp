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

    std::vector res(n, std::vector<int>(m));

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '1')
                q.push({i, j});

    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();

        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if (g[a][b] == '1' || res[a][b])
                continue;
            res[a][b] = res[x][y] + 1;
            q.push({a, b});
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cout << res[i][j] << " \n"[j == m - 1];

    return 0;
}