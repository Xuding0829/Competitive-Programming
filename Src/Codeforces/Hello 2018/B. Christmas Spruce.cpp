#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> deg(n);
    std::vector<int> adj[n];
    std::vector<int> fa(n);
    for (int i = 1; i < n; i++)
    {
        std::cin >> fa[i];
        fa[i]--;
        adj[fa[i]].push_back(i);
        deg[fa[i]]++;
    }

    bool flag = false;

    auto dfs = [&](int u)
    {
        int cnt = 0;
        for (auto v : adj[u])
        {
            if (deg[v] == 0)
                cnt++;
        }

        if (cnt < 3 && deg[u])
            return false;
        else
            return true;
    };

    std::vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        vis[i] = dfs(i);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "YES\n";
    return 0;
}