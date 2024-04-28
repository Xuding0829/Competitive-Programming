#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct BIT
{
    const int n;
    std::vector<T> tr;
    BIT(int n) : n(n), tr(n + 1) {}
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

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    BIT<int> bit(n);

    std::vector<int> greater(n + 1), lower(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int t = a[i];
        lower[i] = bit.sum(t - 1);
        greater[i] = bit.rangesum(t, n);
        bit.add(t, 1);
    }

    bit.clear();

    i64 res1 = 0, res2 = 0;
    for (int i = n; i >= 1; i--)
    {
        int t = a[i];
        res1 += (i64)lower[i] * bit.sum(t - 1);
        res2 += (i64)greater[i] * bit.rangesum(t, n);
        bit.add(t, 1);
    }
    std::cout << res2 << ' ' << res1 << '\n';

    return 0;
}