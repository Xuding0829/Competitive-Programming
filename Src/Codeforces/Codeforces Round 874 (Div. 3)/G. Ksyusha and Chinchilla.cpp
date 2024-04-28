#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    std::vector<int> siz(n);
    std::vector<int> res;
    std::function<void(int, int, int)> dfs = [&](int u, int fa, int idx)
    {
        siz[u] = 1;
        for (auto [v, id] : adj[u])
        {
            if (v == fa)
                continue;
            dfs(v, u, id);
            siz[u] += siz[v];
        }

        if (siz[u] == 3)
        {
            siz[u] = 0;
            if (idx)
                res.push_back(idx);
        }
    };

    dfs(0, -1, 0);

    // for (int i = 0; i < n; i++)
    //     std::cout << i << ' ' << siz[i] << '\n';

    if (siz[0] != 0)
    {
        std::cout << "-1\n";
        return;
    }
    else
    {
        std::cout << res.size() << '\n';
        for (auto x : res)
            std::cout << x << " ";
        std::cout << '\n';
    }
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