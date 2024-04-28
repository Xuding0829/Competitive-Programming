#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a;
    std::cin >> a;

    int cnt = 0;
    for (int i = 0, x; i < 3; i++)
    {
        std::cin >> x;
        if (x > a)
            cnt++;
    }
    std::cout << cnt << '\n';
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