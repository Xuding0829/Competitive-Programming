#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n % 4 == 2)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";

        int sum = 0, sum2 = 0;

        for (int i = 1; i <= n / 2; i++)
            std::cout << i * 2 << ' ', sum += i * 2;
        for (int i = 1; i <= n / 2 - 1; i++)
            std::cout << 2 * i - 1 << ' ', sum2 += 2 * i - 1;
        std::cout << sum - sum2 << '\n';
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