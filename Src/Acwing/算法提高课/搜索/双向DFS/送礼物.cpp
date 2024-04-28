#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> m >> n;

    std::vector<int> g(n);
    for (int i = 0; i < n; i++)
        std::cin >> g[i];
    std::sort(g.begin(), g.end(), std::greater<int>());

    int k = n >> 1;
    std::vector<int> weight;
    std::function<void(int, int)> dfs = [&](int u, int s)
    {
        if (u == k)
        {
            weight.push_back(s);
            return;
        }

        dfs(u + 1, s);
        if ((i64)s + g[u] <= m)
            dfs(u + 1, s + g[u]);
    };
    dfs(0, 0);

    std::sort(weight.begin(), weight.end());
    weight.erase(std::unique(weight.begin(), weight.end()), weight.end());

    int res = 0;
    std::function<void(int, int)> dfs2 = [&](int u, int s)
    {
        if (u == n)
        {
            int l = 0, r = weight.size() - 1;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (weight[mid] <= m - s)
                    l = mid;
                else
                    r = mid - 1;
            }
            res = std::max(res, weight[l] + s);
            return;
        }

        dfs2(u + 1, s);
        if ((i64)s + g[u] <= m)
            dfs2(u + 1, s + g[u]);
    };
    dfs2(k, 0);
    std::cout << res << '\n';

    return 0;
}