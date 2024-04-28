#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 2000;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    std::cin >> m;

    int idx = 0;
    std::vector<int> deg(N);
    std::vector<std::pair<int, int>> adj[N];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back({v, idx++});
        adj[v].push_back({u, idx++});
        deg[u]++, deg[v]++;
    }

    int start = 1;
    while (!deg[start])
        start++;
    for (int i = 1; i <= 500; i++)
    {
        if (deg[i] & 1)
        {
            start = i;
            break;
        }
    }

    std::stack<int> stk;
    std::vector<bool> vis(N);
    std::function<void(int)> dfs = [&](int u)
    {
        for (auto [v, id] : adj[u])
        {
            if (!vis[id])
            {
                vis[id] = true;
                vis[id ^ 1] = true;
                dfs(v);
            }
        }
        stk.push(u);
    };

    for (int i = 1; i <= 500; i++)
        std::sort(adj[i].begin(), adj[i].end());

    dfs(start);
    while (stk.size())
    {
        std::cout << stk.top() << '\n';
        stk.pop();
    }
    return 0;
}