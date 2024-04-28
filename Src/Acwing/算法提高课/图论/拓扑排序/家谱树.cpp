#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> deg(n + 1), adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int son;
        while (std::cin >> son, son)
        {
            adj[i].push_back(son);
            deg[son]++;
        }
    }

    std::queue<int> q;
    std::vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (!deg[i])
            q.push(i), res.push_back(i);
    }

    while (q.size())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            --deg[v];
            if (!deg[v])
                q.push(v), res.push_back(v);
        }
    }

    for (auto x : res)
        std::cout << x << ' ';
    return 0;
}