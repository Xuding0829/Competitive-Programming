#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> w[i];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(2));
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = std::max(f[i - 1][1], f[i - 1][0]);
        f[i][1] = f[i - 1][0] + w[i];
    }

    int res = std::max(f[n][1], f[n][0]);
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