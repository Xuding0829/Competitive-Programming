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

    std::vector<int> init(n), goal(n);
    for (int i = 0; i < n; i++)
        std::cin >> init[i];
    for (int i = 0; i < n; i++)
        std::cin >> goal[i];

    std::vector<int> res;

    std::function<void(int, int, int, int)> dfs = [&](int u, int fa, int odd, int even)
    {
        if (odd)
            init[u] ^= 1;

        if (init[u] != goal[u])
            init[u] ^= 1, res.push_back(u), odd ^= 1;

        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            dfs(v, u, even, odd);
        }
    };

    dfs(0, -1, 0, 0);

    std::cout << res.size() << '\n';
    for (auto i : res)
        std::cout << i + 1 << '\n';
    return 0;
}