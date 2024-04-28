#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, w;
    std::cin >> n >> w;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end(), std::greater<i64>());

    int res = 1e9;
    i64 c[20];
    std::function<void(int, int)> dfs = [&](int x, int cnt)
    {
        if (cnt >= res)
            return;
        if (x == n)
        {
            res = std::min(res, cnt);
            return;
        }

        for (int i = 1; i <= cnt; i++)
        {
            if (c[i] + a[x] <= w)
            {
                c[i] += a[x];
                dfs(x + 1, cnt);
                c[i] -= a[x];
            }
        }

        c[cnt + 1] = a[x];
        dfs(x + 1, cnt + 1);
        c[cnt + 1] = 0;
    };
    dfs(0, 0);

    std::cout << res << '\n';

    return 0;
}