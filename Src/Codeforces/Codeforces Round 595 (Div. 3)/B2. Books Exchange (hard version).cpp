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
        if (x > y)
            std::swap(x, y);
        f[y] = x, siz[x] += siz[y];
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

    DSU t(n);

    for (int i = 0; i < n; i++)
    {
        if (t.same(i, a[i]))
            continue;
        else
            t.merge(i, a[i]);
    }

    for (int i = 0; i < n; i++)
        std::cout << (t.size(a[i]) == 1 ? 1 : t.size(a[i])) << " \n"[i == n - 1];
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

/*
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 100;

int f[N], siz[N], a[N];

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void solve()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        f[i] = i, siz[i] = 1;

    for (int i = 0; i < n; i++)
        std::cin >> a[i], a[i]--;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == i)
            continue;
        else
        {
            int x = find(i), y = find(a[i]);
            f[x] = y;
            siz[y] += siz[x];
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << (siz[find(a[i])] == 1 ? 1 : siz[find(a[i])] / 2) << " \n"[i == n - 1];
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
*/