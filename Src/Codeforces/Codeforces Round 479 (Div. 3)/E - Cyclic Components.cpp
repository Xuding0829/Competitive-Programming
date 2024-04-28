#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> du(n);
    std::vector<int> adj[n];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
        du[u]++, du[v]++;
    }

    int res = 0;
    std::vector<bool> vis(n);
    std::vector<int> st;

    std::function<void(int)> dfs = [&](int u)
    {
        vis[u] = true;
        st.push_back(u);
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            vis[v] = true;
            dfs(v);
        }
    };

    for (int i = 0; i < n; i++)
    {
        st.clear();
        if (vis[i])
            continue;
        dfs(i);

        bool find = true;
        for (auto it : st)
        {
            if (du[it] != 2)
                find = false;
        }
        res += find;
    }
    std::cout << res << '\n';
    return 0;
}