#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int res = 1e9;
    std::vector<int> g[20];

    auto check = [&](int x, int id)
    {
        for (auto t : g[id])
        {
            if (std::__gcd(x, t) != 1)
                return false;
        }
        return true;
    };

    std::function<void(int, int)> dfs = [&](int x, int cnt)
    {
        if (x >= n)
        {
            res = std::min(res, cnt);
            return;
        }

        for (int i = 1; i <= cnt; i++)
        {
            if (check(a[x], i))
            {
                g[i].push_back(a[x]);
                dfs(x + 1, cnt);
                g[i].pop_back();
            }
        }

        g[cnt + 1].push_back(a[x]);
        dfs(x + 1, cnt + 1);
        g[cnt + 1].pop_back();
    };

    dfs(0, 0);
    std::cout << res << '\n';

    return 0;
}