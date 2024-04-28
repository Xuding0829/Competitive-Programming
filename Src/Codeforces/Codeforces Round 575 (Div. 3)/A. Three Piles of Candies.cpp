#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    i64 a, b, c;
    std::cin >> a >> b >> c;

    i64 res = (a + b + c) / 2;
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