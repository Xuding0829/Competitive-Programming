#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 20010;

int tim = 0, cnt = 0, root;
std::vector<int> adj[N];
std::vector<int> dfn(N), low(N);
std::vector<bool> cut(N);

void tarjan(int u)
{
    dfn[u] = low[u] = ++tim;
    int child = 0;
    for (auto v : adj[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                child++;
                if (u != root || child > 1)
                    cut[u] = true;
            }
        }
        else
            low[u] = std::min(low[u], dfn[v]);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (root = 1; root <= n; root++)
    {
        if (!dfn[root])
            tarjan(root);
    }

    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
            cnt++;
    }
    std::cout << cnt << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
            std::cout << i << ' ';
    }
    return 0;
}