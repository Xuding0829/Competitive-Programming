#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1010;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, t = 0;
    while (std::cin >> m, m)
    {
        int n = 0;
        std::vector<int> adj[N];
        while (m--)
        {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            n = std::max({n, u, v});
        }

        int timestamp = 0, root, dc = 0;
        std::vector<int> dfn(N), low(N), dcc[N];
        std::vector<bool> cut(N);
        std::stack<int> stk;
        std::function<void(int)> tarjan = [&](int u)
        {
            dfn[u] = low[u] = ++timestamp;
            stk.push(u);

            if (u == root && adj[u].size() == 0)
            {
                dc++, dcc[dc].push_back(u);
                return;
            } // 孤立点

            int tot = 0;
            for (auto v : adj[u])
            {
                if (!dfn[v])
                {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                    if (dfn[u] <= low[v])
                    {
                        tot++;
                        if (u != root || tot > 1)
                            cut[u] = true;
                        ++dc;
                        int w;
                        do
                        {
                            w = stk.top();
                            stk.pop();
                            dcc[dc].push_back(w);
                        } while (w != v);
                        dcc[dc].push_back(u);
                    }
                }
                else
                    low[u] = std::min(low[u], dfn[v]);
            }
        };

        for (root = 1; root <= n; root++)
        {
            if (!dfn[root])
                tarjan(root);
        }

        i64 res1 = 0, res2 = 1;
        for (int i = 1; i <= dc; i++)
        {
            int cnt = 0;
            for (auto x : dcc[i])
            {
                if (cut[x])
                    cnt++;
            }

            if (cnt == 0)
            {
                if (dcc[i].size() > 1)
                    res1 += 2, res2 *= dcc[i].size() * (dcc[i].size() - 1) / 2;
                else
                    res1++;
            }
            else if (cnt == 1)
                res1++, res2 *= dcc[i].size() - 1;
        }
        std::cout << "Case " << ++t << ": " << res1 << ' ' << res2 << '\n';
    }
    return 0;
}