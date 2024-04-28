#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 1e9 + 7;

constexpr i64 power(i64 a, i64 b, i64 k)
{
    i64 res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct DSU
{
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 0)
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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++)
        std::cin >> b[i], b[i]--;

    DSU t(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (t.same(a[i], b[i]))
            res++;
        else
            t.merge(a[i], b[i]);
    }

    std::cout << power(2, res, mod) << '\n';
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