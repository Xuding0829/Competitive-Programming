#include <bits/stdc++.h>

using i64 = long long;

constexpr double inf = 1e20;

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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    DSU dsu(n);

    std::pair<int, int> q[n];
    for (int i = 0; i < n; i++)
        std::cin >> q[i].first >> q[i].second;

    auto get_dis = [&](std::pair<int, int> a, std::pair<int, int> b)
    {
        double x = a.first - b.first, y = a.second - b.second;
        return sqrt(x * x + y * y);
    };

    std::vector dis(n, std::vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            std::cin >> ch;
            if (i == j)
                dis[i][j] = 0;
            else if (ch == '0')
                dis[i][j] = inf;
            else if (ch == '1')
            {
                dis[i][j] = get_dis(q[i], q[j]);
                dsu.merge(i, j);
            }
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

    std::vector<double> maxn(n), max_block(n);
    double res1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dsu.same(i, j))
                maxn[i] = std::max(maxn[i], dis[i][j]);
        }
        max_block[dsu.leader(i)] = std::max(max_block[dsu.leader(i)], maxn[i]);
    }

    double res2 = inf;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            if (!dsu.same(i, j))
                res2 = std::min(res2, std::max(maxn[i] + get_dis(q[i], q[j]) + maxn[j], std::max(max_block[dsu.leader(i)], max_block[dsu.leader(j)])));
    std::cout << std::fixed << std::setprecision(6) << res2 << '\n';
    // res = std::max(res, block[i], block[j], maxn[i] + dis[i, j] + maxn[j])
    return 0;
}
