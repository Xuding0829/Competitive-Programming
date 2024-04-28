#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;

    int res = (a + b) / 4;
    res = std::min(res, a);
    res = std::min(res, b);
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