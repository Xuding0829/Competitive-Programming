#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector g(n, std::vector<bool>(n));
    while (m--)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        g[x][y] = true;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = g[i][j] | (g[i][k] & g[k][j]);

    std::vector<bool> vis(n);
    std::vector<int> match(n, -1);

    std::function<bool(int)> find = [&](int x) -> bool
    {
        for (int i = 0; i < n; i++)
        {
            if (g[x][i] && !vis[i])
            {
                vis[i] = true;
                if (match[i] == -1 || find(match[i]))
                {
                    match[i] = x;
                    return true;
                }
            }
        }
        return false;
    };

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        std::fill(vis.begin(), vis.end(), false);
        if (find(i))
            res++;
    }
    std::cout << n - res << '\n';

    return 0;
}