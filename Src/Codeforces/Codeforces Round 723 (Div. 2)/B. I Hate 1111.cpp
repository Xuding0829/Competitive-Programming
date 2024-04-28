#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    i64 n;
    std::cin >> n;

    for (int i = 0; i < 11; i++)
    {
        if (n % 11 == 0)
        {
            std::cout << "YES\n";
            return;
        }
        n -= 111;
        if (n < 0)
            break;
    }
    std::cout << "NO\n";
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