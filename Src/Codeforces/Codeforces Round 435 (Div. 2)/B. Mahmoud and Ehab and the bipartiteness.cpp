#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 二分图
    int x = 0, y = 0;
    std::function<void(int, int, int)> dfs = [&](int u, int fa, int col)
    {
        if (col)
            x++;
        else
            y++;

        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            dfs(v, u, !col);
        }
    };
    dfs(0, -1, 0);
    std::cout << (i64)x * y - (n - 1) << '\n';

    return 0;
}