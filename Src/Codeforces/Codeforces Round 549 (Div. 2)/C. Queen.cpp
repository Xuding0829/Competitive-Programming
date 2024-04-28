#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int root;
    std::vector<int> p(n), c(n), bresp(n);
    std::vector<bool> resp(n);
    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i] >> c[i];
        p[i]--;

        if (p[i] == -2)
        {
            root = i;
            resp[i] = true;
            continue;
        }

        adj[p[i]].push_back(i);

        if (c[i])
            resp[i] = false;
        else
            bresp[p[i]]++, resp[i] = true;
    }

    std::vector<int> res;
    std::function<void(int)> dfs = [&](int u)
    {
        if (adj[u].size() == 0)
        {
            if (!resp[u])
            {
                res.push_back(u);
                return;
            }
        }

        if (!bresp[u] && !resp[u])
            res.push_back(u);

        for (auto v : adj[u])
            dfs(v);
    };

    dfs(root);
    std::sort(res.begin(), res.end());
    for (auto x : res)
        std::cout << x + 1 << ' ';
    std::cout << (res.size() == 0 ? "-1" : "\n");

    return 0;
}