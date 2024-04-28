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

    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    std::vector vis(n, std::vector<char>(n));
    std::vector pre(n, std::vector<std::pair<int, int>>(n, {-1, -1}));
    std::queue<std::pair<int, int>> q;
    q.push({0, 0}), vis[0][0] = true;
    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= n)
                continue;
            if (vis[a][b] || g[a][b] == 1)
                continue;
            vis[a][b] = true;
            q.push({a, b});
            pre[a][b] = {x, y};
        }
    }

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         std::cout << pre[i][j].first << ',' << pre[i][j].second <<  "    " << " \n"[j == n - 1];

    std::pair<int, int> end = {n - 1, n - 1};
    std::vector<std::pair<int, int>> res;
    auto [x, y] = end;
    while (x != -1 && y != -1)
    {
        res.push_back({x, y});
        end = pre[x][y];
        x = end.first, y = end.second;
    }

    std::reverse(res.begin(), res.end());
    for (auto [x, y] : res)
        std::cout << x << ' ' << y << '\n';

    return 0;
}