#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n, n)
    {
        i64 sum = 0, mx = 0;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            sum += a[i];
            mx = std::max(mx, 1LL * a[i]);
        }
        std::sort(a.begin(), a.end(), std::greater<int>());

        int cnt, len;
        std::vector<bool> vis(n);
        std::function<bool(int, int, int)> dfs = [&](int now, int cab, int last)
        {
            if (now > cnt)
                return true;
            if (cab == len)
                return dfs(now + 1, 0, 0);

            int fail = 0;
            for (int i = last; i <= n; i++)
            {
                if (!vis[i] && cab + a[i] <= len && fail != a[i])
                {
                    vis[i] = true;
                    if (dfs(now, cab + a[i], i + 1))
                        return true;
                    fail = a[i];
                    vis[i] = false;
                    if (cab == 0 || cab + a[i] == len)
                        return false;
                }
            }
            return false;
        };

        for (len = mx; len <= sum; len++)
        {
            if (sum % len)
                continue;
            cnt = sum / len;
            std::fill(vis.begin(), vis.end(), false);
            if (dfs(1, 0, 0))
            {
                std::cout << len << '\n';
                break;
            }
        }
    }

    return 0;
}