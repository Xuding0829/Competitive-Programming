#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, p;
    std::cin >> n >> p;

    std::map<int, bool> vis;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], vis[a[i]] = true;

    bool flag = true;
    for (int i = 0; i < a[n]; i++)
    {
        if (!vis[i])
        {
            flag = false;
            break;
        }
    }

    if (flag) // 不进位
    {
        int cur = p - 1;
        while (vis[cur])
            cur--;
        std::cout << std::max(0, cur - a[n]) << '\n';
    }
    else // 进位
    {
        int res = p - a[n];
        int t = a[n];
        for (int i = n - 1; ~i; i--)
        {
            a[i]++;
            if (a[i] == p)
                a[i] = 0;
            vis[a[i]] = true;
            if (a[i])
                break;
        }

        int cur = a[n];
        while (vis[cur])
            cur--;
        res += std::max(0, cur);
        std::cout << res << '\n';
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