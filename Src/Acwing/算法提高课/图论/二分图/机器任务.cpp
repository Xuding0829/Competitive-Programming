#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n, n)
    {
        int m, k;
        std::cin >> m >> k;

        std::vector g(n, std::vector<bool>(m));
        while (k--)
        {
            int t, x, y;
            std::cin >> t >> x >> y;
            if (!x || !y)
                continue;
            g[x][y] = true;
        }

        std::vector<bool> vis(std::max(n, m));
        std::vector<int> match(std::max(n, m));
        std::function<bool(int)> find = [&](int u) -> bool
        {
            for (int v = 1; v < m; v++)
            {
                if (!vis[v] && g[u][v])
                {
                    vis[v] = true;
                    int t = match[v];
                    if (t == 0 || find(t))
                    {
                        match[v] = u;
                        return true;
                    }
                }
            }
            return false;
        };

        int res = 0;
        for (int i = 1; i < n; i++)
        {
            std::fill(vis.begin(), vis.end(), false);
            if (find(i))
                res++;
        }
        std::cout << res << '\n';
    }
    return 0;
}