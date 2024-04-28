#include <bits/stdc++.h>

using i64 = long long;

struct DSU
{
    std::vector<int> f, siz, d;
    DSU(int n) : f(n), siz(n, 1), d(n, 0)
    {
        std::iota(f.begin(), f.end(), 0);
    }
    int leader(int x)
    {
        if (x != f[x])
        {
            int tmp = f[x];
            f[x] = leader(f[x]);
            d[x] += d[tmp];
        }
        return f[x];
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
            f[x] = y;
            d[x] += siz[y];
            siz[y] += siz[x];
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

    int T;
    std::cin >> T;

    DSU dsu(30010);

    while (T--)
    {
        char op;
        int i, j;
        std::cin >> op >> i >> j;
        i--, j--;

        if (op == 'M')
        {
            dsu.merge(i, j);
        }
        else
        {
            if (dsu.same(i, j))
                std::cout << std::max(0, std::abs(dsu.d[j] - dsu.d[i]) - 1) << '\n';
            else
                std::cout << "-1\n";
        }
    }

    return 0;
}