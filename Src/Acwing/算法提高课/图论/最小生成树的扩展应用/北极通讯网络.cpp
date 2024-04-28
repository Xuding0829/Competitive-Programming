#include <bits/stdc++.h>

using i64 = long long;

struct edge
{
    int u, v;
    double w;
    bool operator<(const edge &t) const
    {
        return w < t.w;
    }
};

struct DSU
{
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1)
    {
        std::iota(f.begin(), f.end(), 0);
    }
    int leader(int x)
    {
        return x == f[x] ? x : f[x] = leader(f[x]);
    }
    bool same(int x, int y)
    {
        return leader(x) == leader(y);
    }
    void merge(int x, int y)
    {
        x = leader(x), y = leader(y);
        if (x != y)
        {
            siz[x] += siz[y];
            f[y] = x;
        }
    }
    int size(int x)
    {
        return siz[leader(x)];
    }
};

double get_dis(std::pair<int, int> x, std::pair<int, int> y)
{
    return std::sqrt(double((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second)));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> point(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        point[i] = {x, y};
    }

    std::vector<edge> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dis = get_dis(point[i], point[j]);
            adj.push_back({i, j, dis});
        }
    }

    DSU dsu(n);
    std::sort(adj.begin(), adj.end());

    // for (auto [u, v, w] : adj)
    //     std::cout << u << ' ' << v << ' ' << std::fixed << std::setprecision(2) << w << '\n';

    int cnt = n;
    double res;
    for (auto [u, v, w] : adj)
    {
        if (dsu.same(u, v))
            continue;
        else
        {
            dsu.merge(u, v);
            cnt--;
            res = w;
        }

        if (cnt <= k)
            break;
    }
    std::cout << std::fixed << std::setprecision(2) << res << '\n';

    return 0;
}