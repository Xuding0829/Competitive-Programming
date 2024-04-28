#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    i64 sum = std::accumulate(a.begin(), a.end(), 0);

    auto is_composite = [=](int x)
    {
        for (int i = 2; i <= x / i; i++)
            if (x % i == 0)
                return true;
        return false;
    };

    if (is_composite(sum))
    {
        std::cout << n << '\n';
        for (int i = 1; i <= n; i++)
            std::cout << i << " \n"[i == n];
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (is_composite(sum - a[i]))
            {
                std::cout << n - 1 << '\n';
                for (int j = 0; j < n; j++)
                    if (i != j)
                        std::cout << j + 1 << ' ';
                std::cout << '\n';
                return;
            }
        }
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