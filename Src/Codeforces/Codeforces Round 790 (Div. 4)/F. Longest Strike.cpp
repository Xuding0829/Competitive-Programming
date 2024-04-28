#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::map<int, int> mp;
    for (int i = 0; i < n; i++)
        std::cin >> a[i], mp[a[i]]++;

    std::vector<int> v;
    for (auto [i, j] : mp)
        if (j >= k)
            v.push_back(i);

    if (!v.size())
    {
        std::cout << "-1\n";
        return;
    }
    else
    {
        int res_l = v[0], res_r = v[0];

        int l = 0, r = 0, len = 0;
        while (r < v.size())
        {
            if (v[r] - v[l] == r - l)
                r++;
            else
            {
                if (len < v[r - 1] - v[l])
                    len = v[r - 1] - v[l], res_l = v[l], res_r = v[r - 1];
                l = r, r++;
            }
        }

        if (len < v[r - 1] - v[l])
            len = v[r - 1] - v[l], res_l = v[l], res_r = v[r - 1];
        std::cout << res_l << ' ' << res_r << '\n';
    }
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