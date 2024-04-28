#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<bool> vis(n + 1);
    std::vector<int> res;
    res.push_back(1);
    vis[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        for (int j = i; j <= n; j <<= 1)
        {
            if (vis[j])
                continue;
            else
            {
                res.push_back(j);
                vis[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        std::cout << res[i] << " \n"[i == n - 1];
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