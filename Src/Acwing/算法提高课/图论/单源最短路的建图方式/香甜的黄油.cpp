#include <bits/stdc++.h>

using i64 = long long;
using PII = std::pair<int, int>;

constexpr int N = 1000, inf = 0x3f3f3f;

struct edge
{
    int to, w;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p, m;
    std::cin >> n >> p >> m;

    std::vector<int> cnt(p + 1);
    for (int i = 1, x; i <= n; i++)
        std::cin >> x, cnt[x]++;

    std::vector<edge> g[N];
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    std::vector<int> dis(p + 1, inf);

    std::function<void(int)> spfa = [&](int start)
    {
        std::fill(dis.begin(), dis.end(), inf);
        std::bitset<N> st;
        dis[start] = 0;

        std::queue<int> q;
        q.push(start);
        st[start] = true;

        while (q.size())
        {
            int t = q.front();
            q.pop();
            st[t] = false;

            for (int i = 0; i < g[t].size(); i++)
            {
                int to = g[t][i].to, w = g[t][i].w;
                if (dis[to] > dis[t] + w)
                {
                    dis[to] = dis[t] + w;
                    if (!st[to])
                        q.push(to), st[to] = true;
                }
            }
        }
    };

    std::function<void(int)> dijkstra = [&](int start)
    {
        std::fill(dis.begin(), dis.end(), inf);
        std::bitset<N> st;
        dis[start] = 0;

        std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
        q.push({0, start});
        while (q.size())
        {
            auto t = q.top();
            q.pop();
            int pre = t.second;

            if (st[pre])
                continue;
            st[pre] = true;

            for (int i = 0; i < g[pre].size(); i++)
            {
                int to = g[pre][i].to, w = g[pre][i].w;
                if (dis[to] > dis[pre] + w)
                    dis[to] = dis[pre] + w, q.push({dis[to], to});
            }
        }
    };

    int res = inf;
    for (int i = 1; i <= p; i++)
    {
        spfa(i);
        int sum = 0;
        bool flag = true;

        for (int j = 1; j <= p; j++)
        {
            if (cnt[j])
            {
                if (dis[j] == inf) // 不能走到
                {
                    flag = false;
                    break;
                }
                sum += cnt[j] * dis[j];
            }
        }
        if (flag)
            res = std::min(res, sum);
    }
    std::cout << res << '\n';

    return 0;
}