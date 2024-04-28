#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n, n)
    {
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];

        int res = n;

        std::vector<int> up(n), down(n);
        std::function<void(int, int, int)> dfs = [&](int u, int su, int sd)
        {
            if (su + sd >= res)
                return;
            if (u == n)
            {
                res = su + sd;
                return;
            }

            // up
            int k = 0;
            while (k < su && up[k] >= a[u])
                k++;
            int t = up[k];
            up[k] = a[u];
            if (k >= su)
                dfs(u + 1, su + 1, sd);
            else
                dfs(u + 1, su, sd);
            up[k] = t;

            // down
            k = 0;
            while (k < sd && down[k] <= a[u])
                k++;
            t = down[k];
            down[k] = a[u];
            if (k >= sd)
                dfs(u + 1, su, sd + 1);
            else
                dfs(u + 1, su, sd);
            down[k] = t;
        };

        dfs(0, 0, 0);

        std::cout << res << '\n';
    }

    return 0;
}