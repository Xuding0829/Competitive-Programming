#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick
{
    const int n;
    std::vector<T> tr;
    Fenwick(int n) : n(n), tr(n + 1) {}
    void clear()
    {
        std::fill(tr.begin(), tr.end(), 0);
    }
    void add(int x, int c)
    {
        for (int i = x; i <= n; i += i & -i)
            tr[i] += c;
    }
    T sum(int x)
    {
        T res = 0;
        for (int i = x; i; i -= i & -i)
            res += tr[i];
        return res;
    }
    T rangesum(int l, int r)
    {
        return sum(r) - sum(l);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    Fenwick<int> fen(n);

    std::vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], s[i] = a[i] - a[i - 1], fen.add(i, s[i]);

    while (m--)
    {
        char op[2];
        std::cin >> op;
        if (op[0] == 'C')
        {
            int l, r, d;
            std::cin >> l >> r >> d;
            fen.add(l, d), fen.add(r + 1, -d);
        }
        else
        {
            int x;
            std::cin >> x;
            std::cout << fen.sum(x) << '\n';
        }
    }

    return 0;
}
