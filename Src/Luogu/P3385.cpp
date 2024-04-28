#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> adj[n];
    while (m--)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        if (w >= 0)
            adj[v].push_back({u, w});
    }

    std::vector<int> dis(n, inf);
    std::vector<bool> st(n, false);
    std::vector<int> cnt(n);

    std::function<void(void)> spfa = [&]()
    {
        std::fill(dis.begin(), dis.end(), inf);
        std::fill(st.begin(), st.end(), false);
        std::fill(cnt.begin(), cnt.end(), 0);
        dis[0] = 0, st[0] = true;
        std::queue<int> q;
        q.push(0);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            st[u] = false;

            for (auto [v, w] : adj[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] == n)
                    {
                        std::cout << "YES\n";
                        return;
                    }
                    if (!st[v])
                    {
                        st[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        std::cout << "NO\n";
    };

    spfa();
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