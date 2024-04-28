#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> segs(n);
    for (int i = 0; i < n; i++)
    {
        int l, r, a, b;
        std::cin >> l >> r >> a >> b;
        segs[i] = {l, b};
    }

    std::sort(segs.begin(), segs.end());
    int st = -1e9, ed = -1e9;
    std::vector<std::pair<int, int>> tmp;
    for (auto [x, y] : segs)
    {
        if (ed < x)
        {
            if (st != -1e9)
                tmp.push_back({st, ed});
            st = x, ed = y;
        }
        else
            ed = std::max(ed, y);
    }
    if (st != -1e9)
        tmp.push_back({st, ed});
    segs = tmp; // 区间合并

    int x;
    auto check = [&](int mid)
    {
        if (segs[mid].first <= x)
            return true;
        else
            return false;
    }; // 二分的check函数

    int q;
    std::cin >> q;
    while (q--)
    {
        std::cin >> x;

        int l = 0, r = segs.size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        if (segs[l].first <= x && x <= segs[l].second)
            std::cout << segs[l].second << ' ';
        else
            std::cout << x << ' ';
    }
    std::cout << '\n';
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