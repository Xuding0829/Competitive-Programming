#include <bits/stdc++.h>

using i64 = long long;

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

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], a[i]--;

    DSU dsu(n);
    for (int i = 0; i < n; i++)
        dsu.merge(i, a[i]);

    bool chain = false;
    int minn = 0, maxn = 0;

    std::vector<int> e(n);
    for (int i = 0; i < n; i++)
    {
        if (a[a[i]] == i)
            e[dsu.leader(i)] = 1, chain = true; // 判链
    }

    for (int i = 0; i < n; i++)
    {
        if (dsu.leader(i) == i)
        {
            if (!e[i]) // 判环
                minn++;
            maxn++; // 最大：连通块数量
        }
    }

    minn += chain; // 最小：环 + 链（0/1）
    std::cout << minn << ' ' << maxn << '\n';
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