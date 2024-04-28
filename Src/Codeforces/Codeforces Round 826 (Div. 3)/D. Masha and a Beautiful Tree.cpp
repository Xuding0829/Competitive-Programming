#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    int res = 0;
    bool flag = false;
    std::function<void(int, int)> dfs = [&](int l, int r)
    {
        if (l >= r)
            return;

        int mid = l + r >> 1;
        int len = r - l + 1 >> 1;

        dfs(l, mid), dfs(mid + 1, r);

        if (a[l] > a[l + len])
            res++, std::swap(a[l], a[l + len]);
        if (a[l] + len != a[l + len])
            flag = true;
    };

    dfs(1, n);

    std::cout << (flag ? -1 : res) << '\n';
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