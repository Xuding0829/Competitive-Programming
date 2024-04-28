#include <bits/stdc++.h>

using i64 = long long;
template <typename T>
struct Flow
{
    static constexpr i64 INF = 1e18;
    int n;
    struct Edge
    {
        int to;
        T cap;
        Edge(int to, T cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, dep;
    Flow(int n) : n(n), g(n) {}
    bool bfs(int s, int t)
    {
        dep.assign(n, -1);
        std::queue<int> q;
        q.push(s);
        dep[s] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();

            for (int i : g[u])
            {
                int v = e[i].to;
                int c = e[i].cap;
                if (dep[v] == -1 && c > 0)
                {
                    dep[v] = dep[u] + 1;
                    if (v == t)
                        return true;
                    q.push(v);
                }
            }
        }
        return false;
    }
    T dfs(int u, int t, T f)
    {
        if (u == t)
            return f;
        T r = f;
        for (int &i = cur[u]; i < int(g[u].size()); i++)
        {
            int j = g[u][i];
            int v = e[j].to;
            T c = e[j].cap;
            if (c > 0 && dep[v] == dep[u] + 1)
            {
                T a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c)
    {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T maxFlow(int s, int t)
    {
        T ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n, 0);
            ans += dfs(s, t, INF);
        }
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    s--, t--;

    Flow<i64> flow(n);
    while (m--)
    {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--, v--;
        flow.addEdge(u, v, c);
    }
    std::cout << flow.maxFlow(s, t) << '\n';

    return 0;
}