#include <bits/stdc++.h>

using i64 = long long;

const int mod = 1e9 + 7;

void solve()
{
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int res1 = y2 - y1;
    if (res1 < 0)
    {
        std::cout << "-1\n";
        return;
    }
    int x = x1 + res1;

    int res2 = x - x2;
    if (res2 < 0)
    {
        std::cout << "-1\n";
        return;
    }

    std::cout << res1 + res2 << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    while (n--)
    {
        solve();
    }
    return 0;
}
