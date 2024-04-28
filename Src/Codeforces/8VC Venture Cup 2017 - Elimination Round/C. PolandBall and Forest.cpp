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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    DSU dsu(n);
    for (int i = 0; i < n; i++)
    {
        int p;
        std::cin >> p;
        p--;
        dsu.merge(std::min(i, p), std::max(i, p));
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        res += i == dsu.leader(i);
    std::cout << res << '\n';
    return 0;
}