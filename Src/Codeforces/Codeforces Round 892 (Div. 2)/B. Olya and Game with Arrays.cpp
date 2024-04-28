#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    i64 minn = 1e18, sum = 0, smin = 1e18;
    std::vector<i64> a[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;
        while (m--)
        {
            int x;
            std::cin >> x;
            a[i].push_back(x);
        }
        std::sort(a[i].begin(), a[i].end());
        minn = std::min(minn, a[i][0]);
        smin = std::min(smin, a[i][1]);
        sum += a[i][1];
    }
    std::cout << sum + minn - smin << '\n';
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