#include <bits/stdc++.h>

using i64 = long long;

struct DSU
{
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
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
            siz[y] += siz[x];
            f[x] = y;
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

    int n, m;
    std::cin >> n >> m;

    DSU dsu(n * n);

    for (int i = 1; i <= m; i++)
    {
        char op;
        int a, b;
        std::cin >> a >> b >> op;
        a--, b--;
        int x = a * n + b, y;
        if (op == 'D')
            y = (a + 1) * n + b;
        else
            y = a * n + b + 1;
        if (dsu.same(x, y))
        {
            std::cout << i << '\n';
            return 0;
        }
        dsu.merge(x, y);
    }
    std::cout << "draw\n";

    return 0;
}