#include <bits/stdc++.h>

using i64 = long long;

struct Edge
{
    int v, w;
};

constexpr int N = 5100;
constexpr int inf = 0x3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, res = 0;
    std::cin >> n >> m;

    std::vector<Edge> e[N];
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }

    auto prim = [&]() -> bool
    {
        int cnt = 0;

        std::vector<int> dis(N, inf);
        dis[1] = 0;

        std::bitset<N> st;

        std::priority_queue<std::pair<int, int>> q;
        q.push({0, 1});
        while (q.size())
        {
            auto u = q.top().second;
            q.pop();
            if (st[u])
                continue;
            st[u] = 1;
            res += dis[u], cnt++;
            for (auto ed : e[u])
            {
                int v = ed.v, w = ed.w;
                dis[v] = std::min(dis[v], w);
                q.push({-dis[v], v});
            }
        }
        return cnt == n;
    };

    bool t = prim();
    if (t)
        std::cout << res << '\n';
    else
        std::cout << "orz\n";

    return 0;
}