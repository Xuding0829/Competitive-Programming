#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick
{
    const int n;
    std::vector<int> t;
    Fenwick(int n) : n(n), t(n + 1) {}
    void add(int x, T c)
    {
        for (int i = x; i <= n; i += i & -i)
            t[i] += c;
    }
    T sum(int x)
    {
        T res = 0;
        for (int i = x; i; i -= i & -i)
            res += t[i];
        return res;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> tr(n + 1);

    auto add = [&](int x, int v) -> void
    {
        for (int i = x; i <= n; i += i & -i)
            tr[i] += v;
    };

    auto sum = [&](int x)
    {
        int res = 0;
        for (int i = x; i; i -= i & -i)
            res += tr[i];
        return res;
    };

    std::vector<int> a(n + 1), res(n + 1);
    for (int i = 2; i <= n; i++)
        std::cin >> a[i];

    for (int i = 1; i <= n; i++)
        add(i, 1);

    for (int i = n; i >= 1; i--)
    {
        int k = a[i] + 1;
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (sum(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        res[i] = l;
        add(l, -1);
    }

    for (int i = 1; i <= n; i++)
        std::cout << res[i] << '\n';

    return 0;
}