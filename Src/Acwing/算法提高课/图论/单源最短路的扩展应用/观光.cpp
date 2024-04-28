#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

struct node
{
    int id, type, dist;
    bool operator>(const node &w) const
    {
        return dist > w.dist;
    }
};

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
    }

    int s, f;
    std::cin >> s >> f;
    s--, f--;

    auto dijkstra = [&]()
    {
        std::vector vis(n, std::vector<bool>(2, false));
        std::vector dis(n, std::vector<int>(2, inf));
        std::vector cnt(n, std::vector<int>(2));
        dis[s][0] = 0, cnt[s][0] = 1;

        std::priority_queue<node, std::vector<node>, std::greater<node>> q;
        q.push({s, 0, 0});
        while (q.size())
        {
            auto t = q.top();
            q.pop();

            int u = t.id, type = t.type;
            if (vis[u][type])
                continue;
            vis[u][type] = true;

            for (auto [v, w] : adj[u])
            {
                if (dis[v][0] > dis[u][type] + w)
                {
                    dis[v][1] = dis[v][0];
                    cnt[v][1] = cnt[v][0];
                    q.push({v, 1, dis[v][1]});

                    dis[v][0] = dis[u][type] + w;
                    cnt[v][0] = cnt[u][type];
                    q.push({v, 0, dis[v][0]});
                }
                else if (dis[v][0] == dis[u][type] + w)
                {
                    cnt[v][0] += cnt[u][type];
                }
                else if (dis[v][1] > dis[u][type] + w)
                {
                    dis[v][1] = dis[u][type] + w;
                    cnt[v][1] = cnt[u][type];
                    q.push({v, 1, dis[v][1]});
                }
                else if (dis[v][1] == dis[u][type] + w)
                {
                    cnt[v][1] += cnt[u][type];
                }
            }
        }

        int res = cnt[f][0];
        res += (dis[f][0] + 1 == dis[f][1] ? cnt[f][1] : 0);
        return res;
    };
    std::cout << dijkstra() << '\n';
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