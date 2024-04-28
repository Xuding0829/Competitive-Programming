#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    bool flag = false;
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        if (x < 0)
            flag = true;
    }

    if (flag)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        std::cout << "101\n";
        for (int i = 0; i < 101; i++)
            std::cout << i << " \n"[i == 100];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}