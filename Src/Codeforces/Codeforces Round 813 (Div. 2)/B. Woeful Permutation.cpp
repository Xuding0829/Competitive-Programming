#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n == 1)
        std::cout << 1 << '\n';
    else
    {
        std::vector<int> a(n + 1);
        if (n & 1)
        {
            a[1] = 1;
            for (int i = 2; i <= n; i += 2)
                a[i] = i + 1, a[i + 1] = i;
        }
        else
        {
            for (int i = 1; i <= n; i += 2)
                a[i] = i + 1, a[i + 1] = i;
        }

        for (int i = 1; i <= n; i++)
            std::cout << a[i] << ' ';
        std::cout << '\n';
    }
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