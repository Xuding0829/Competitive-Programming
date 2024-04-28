#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> fa(n);
    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> fa[i];
        fa[i]--;
        if (fa[i] != -2)
            adj[fa[i]].push_back(i);
    }

    int res = 0;
    std::vector<int> dep(n);

    std::function<void(int)> dfs = [&](int u)
    {
        res = std::max(res, dep[u] + 1);
        for (auto v : adj[u])
        {
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    };

    for (int i = 0; i < n; i++)
        if (fa[i] == -2)
            dfs(i);

    std::cout << res << '\n';
    return 0;
}