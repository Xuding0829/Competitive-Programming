#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int res = 0;
    std::function<void(int, int, int)> dfs = [&](int u, int fa, int cat)
    {
        if (cat > m)
            return;
        if (adj[u].size() == 1 && fa != -1)
            res++;
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            if (a[v])
                dfs(v, u, cat + a[v]);
            else
                dfs(v, u, a[v]);
        }
    };

    dfs(0, -1, a[0]);
    std::cout << res << '\n';

    return 0;
}