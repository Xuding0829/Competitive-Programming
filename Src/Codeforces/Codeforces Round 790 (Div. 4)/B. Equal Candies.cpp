#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int minn = 1e9;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], minn = std::min(minn, a[i]);

    int res = 0;
    for (int i = 0; i < n; i++)
        res += a[i] - minn;

    std::cout << res << '\n';
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