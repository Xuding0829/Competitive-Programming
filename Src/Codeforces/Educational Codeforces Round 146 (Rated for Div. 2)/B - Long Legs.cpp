#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;

    int res = 1e9;
    for (int i = 1; i <= 100000; i++)
        res = std::min(res, i - 1 + (int)ceil(a * 1.0 / i) + (int)ceil(b * 1.0 / i));
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