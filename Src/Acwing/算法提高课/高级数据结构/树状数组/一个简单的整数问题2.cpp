#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick
{
    const int n;
    std::vector<T> tr, tri;
    Fenwick(int n) : n(n), tr(n + 1), tri(n + 1) {}
    void add(int x, T c)
    {
        for (int i = x; i <= n; i += i & -i)
            tr[i] += c;
    }
    void addi(int x, T c)
    {
        for (int i = x; i <= n; i += i & -i)
            tri[i] += c;
    }
    T sum(int x)
    {
        T res = 0;
        for (int i = x; i; i -= i & -i)
            res += tr[i];
        return res;
    }
    T sumi(int x)
    {
        T res = 0;
        for (int i = x; i; i -= i & -i)
            res += tri[i];
        return res;
    }
    T sum_point(int x)
    {
        return (i64)(x + 1) * sum(x) - sumi(x);
    }
    T get_sum(int l, int r)
    {
        return sum_point(r) - sum_point(l - 1);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    Fenwick<i64> fen(n);

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], fen.add(i, a[i] - a[i - 1]), fen.addi(i, (a[i] - a[i - 1]) * i);

    while (m--)
    {
        char op[2];
        std::cin >> op;
        if (op[0] == 'C')
        {
            int l, r, d;
            std::cin >> l >> r >> d;
            fen.add(l, d), fen.add(r + 1, -d);
            fen.addi(l, l * d), fen.addi(r + 1, (r + 1) * (-d));
        }
        else
        {
            int l, r;
            std::cin >> l >> r;

            // 暴力写法
            // for (int i = l; i <= r; i++)
            //     res += fen.sum(i);

            std::cout << fen.get_sum(l, r) << '\n';
        }
    }

    return 0;
}