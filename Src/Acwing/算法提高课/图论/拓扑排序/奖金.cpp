#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> deg(n + 1);
    std::vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        std::cin >> v >> u;
        adj[u].push_back(v);
        deg[v]++;
    }

    std::queue<int> q;
    std::vector<int> tmp, salary(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!deg[i])
        {
            q.push(i);
            salary[i] = 100;
            tmp.push_back(i);
        }
    }
    while (q.size())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            --deg[v];
            if (!deg[v])
            {
                tmp.push_back(v);
                q.push(v), salary[v] = salary[u] + 1;
            }
        }
    }

    if (tmp.size() < n)
        std::cout << "Poor Xed\n";
    else
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += salary[i];
        std::cout << res << '\n';
    }
    return 0;
}