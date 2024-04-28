#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector g(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> g[i][j];

    int peak = 0, valley = 0;
    bool has_lower = false, has_higher = false;
    std::vector vis(n, std::vector<bool>(n));

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
                for (int b = y - 1; b <= y + 1; b++)
                {
                    if (a == x && b == y)
                        continue;
                    if (a < 0 || a >= n || b < 0 || b >= n)
                        continue;
                    if (g[a][b] != g[x][y])
                    {
                        if (g[a][b] > g[x][y])
                            has_higher = true;
                        else
                            has_lower = true;
                    }
                    else if (!vis[a][b])
                    {
                        q.push({a, b});
                        vis[a][b] = true;
                    }
                }
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                has_lower = false, has_higher = false;
                bfs(i, j);
                if (!has_lower)
                    valley++;
                if (!has_higher)
                    peak++;
            }
        }
    std::cout << peak << ' ' << valley << '\n';

    return 0;
}