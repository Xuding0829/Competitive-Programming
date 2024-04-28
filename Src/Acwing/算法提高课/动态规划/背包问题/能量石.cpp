#include <bits/stdc++.h>

using i64 = long long;

struct Stone
{
    int s, e, l;
    bool operator<(const Stone &x) const
    {
        return s * x.l < l * x.s;
    }
};

void solve()
{
    int n;
    std::cin >> n;

    int m = 0;
    std::vector<Stone> st(n);
    for (int i = 0; i < n; i++)
    {
        int s, e, l;
        std::cin >> s >> e >> l;
        st[i] = {s, e, l}, m += s;
    }
    std::sort(st.begin(), st.end());

    std::vector<int> f(m + 1, -0x3f);
    f[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = m; j >= st[i].s; j--)
            f[j] = std::max(f[j], f[j - st[i].s] + st[i].e - st[i].l * (j - st[i].s));

    int res = 0;
    for (int i = 0; i <= m; i++)
        res = std::max(res, f[i]);
    std::cout << res << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}