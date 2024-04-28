#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e5 + 100;

void solve()
{
    int n;
    std::cin >> n;

    auto is_prime = [](int x) -> bool
    {
        if (x <= 1)
            return false;
        for (int i = 2; i <= x / i; i++)
            if (x % i == 0)
                return false;
        return true;
    };

    int t = n;
    while (is_prime(t) || !is_prime(t + n - 1))
        t++;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (i != j)
                std::cout << 1 << ' ';
            else
                std::cout << t << ' ';
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
