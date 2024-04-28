#include <bits/stdc++.h>

using i64 = long long;

const i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> adj[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    std::vector<i64> dis(n, -inf);
    std::vector<bool> st(n, false);
    std::vector<int> cnt(n, 0);

    std::function<void(void)> spfa = [&]()
    {
        dis[0] = 0;
        st[0] = true;

        std::queue<int> q;
        q.push(0);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            st[u] = false;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] < dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] == 2 * n)
                    {
                        return;
                    }
                    if (!st[v])
                    {
                        q.push(v);
                        st[v] = true;
                    }
                }
            }
        }
    };

    spfa();

    if (cnt[n - 1] >= n)
        std::cout << "inf\n";
    else
        std::cout << dis[n - 1] << '\n';
    return 0;
}