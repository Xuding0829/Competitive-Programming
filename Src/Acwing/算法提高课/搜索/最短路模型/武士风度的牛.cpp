#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> m >> n;

    std::pair<int, int> st, ed;
    std::vector g(n, std::vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            std::cin >> g[i][j];
            if (g[i][j] == 'K')
                st = {i, j};
            else if (g[i][j] == 'H')
                ed = {i, j};
        }

    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    std::vector dis(n, std::vector<int>(m, -1));
    auto bfs = [&]()
    {
        std::queue<std::pair<int, int>> q;
        q.push(st);
        dis[st.first][st.second] = 0;
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x == ed.first && y == ed.second)
                return dis[x][y];

            for (int i = 0; i < 8; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m)
                    continue;
                if (g[a][b] == '*' || dis[a][b] != -1)
                    continue;

                dis[a][b] = dis[x][y] + 1;
                q.push({a, b});
            }
        }
        return -1;
    };

    std::cout << bfs() << '\n';
    return 0;
}