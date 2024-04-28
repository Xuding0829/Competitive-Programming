#include <bits/stdc++.h>

using i64 = long long;

void solve2()
{
    int n;
    std::cin >> n;

    int root;
    std::vector<int> adj[n];
    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        p[i]--;
        if (i == p[i])
            root = i;
        else
            adj[p[i]].push_back(i);
    }

    std::vector<int> res[n];

    std::function<void(int, int)> dfs2 = [&](int u, int root)
    {
        res[root].push_back(u);
        if (!adj[u].size())
            return;

        dfs2(adj[u][0], root);

        for (int i = 1; i < adj[u].size(); i++)
            dfs2(adj[u][i], adj[u][i]);
    };

    dfs2(root, root);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (res[i].size() != 0)
            cnt++;
    std::cout << cnt << '\n';

    for (int i = 0; i < n; i++)
    {
        if (res[i].size())
        {
            std::cout << res[i].size() << '\n';
            for (auto v : res[i])
                std::cout << v + 1 << ' ';
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

void solve()
{
    int n;
    std::cin >> n;

    int root;
    std::vector<int> p(n);
    std::vector<bool> vis(n), leaf(n, true);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        p[i]--;
        if (i != p[i])
            leaf[p[i]] = false;
    }

    std::cout << std::count(leaf.begin(), leaf.end(), true) << "\n";

    for (int i = 0; i < n; i++)
    {
        if (leaf[i])
        {
            std::vector<int> a;
            for (int j = i; !vis[j]; j = p[j])
            {
                vis[j] = true;
                a.push_back(j);
            }

            std::reverse(a.begin(), a.end());

            std::cout << a.size() << '\n';
            for (auto it : a)
                std::cout << it + 1 << " \n"[it == a.back()];
        }
    }
    std::cout << '\n';
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