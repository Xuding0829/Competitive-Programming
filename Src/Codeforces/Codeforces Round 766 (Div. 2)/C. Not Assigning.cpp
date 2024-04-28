#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> adj[n];
    std::vector<std::pair<int, int>> edge(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edge[i] = {u, v};
    }

    int pos;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() > 2)
        {
            std::cout << -1 << '\n';
            return;
        }
        else if (adj[i].size() == 1)
        {
            pos = i;
        }
    }

    std::vector<bool> vis(n);
    std::map<std::pair<int, int>, int> mp;
    std::function<void(int, int, bool)> dfs = [&](int u, int fa, bool flag)
    {
        for (auto it : adj[u])
        {
            int v = it.first, i = it.second;
            if (v == fa)
                continue;
            if (flag)
                mp[{u, v}] = mp[{v, u}] = 2;
            else
                mp[{u, v}] = mp[{v, u}] = 3;
            dfs(v, u, !flag);
        }
    };
    dfs(pos, -1, flag);
    for (int i = 0; i < n - 1; i++)
        std::cout << mp[edge[i]] << " \n"[i == n - 2];
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