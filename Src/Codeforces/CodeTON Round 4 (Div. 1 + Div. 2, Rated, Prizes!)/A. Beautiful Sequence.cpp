#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    bool res = false;
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        if (x <= i)
            res = true;
    }
    std::cout << (res ? "YES\n" : "NO\n");
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