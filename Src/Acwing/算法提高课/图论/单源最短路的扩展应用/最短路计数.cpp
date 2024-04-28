#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr int mod = 100003;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> cnt(n);
    cnt[0] = 1;

    auto bfs = [&]()
    {
        std::vector<bool> vis(n);
        std::vector<int> dis(n, inf);
        dis[0] = 0;

        std::queue<int> q;
        q.push(0);
        while (q.size())
        {
            int u = q.front();
            q.pop();

            if (vis[u])
                continue;
            vis[u] = true;

            for (auto v : adj[u])
            {
                if (dis[v] > dis[u] + 1)
                {
                    dis[v] = dis[u] + 1;
                    cnt[v] = cnt[u];
                    q.push(v);
                }
                else if (dis[v] == dis[u] + 1)
                {
                    cnt[v] = (cnt[v] + cnt[u]) % mod;
                }
            }
        }
    };

    bfs();

    for (int i = 0; i < n; i++)
        std::cout << cnt[i] << '\n';

    return 0;
}