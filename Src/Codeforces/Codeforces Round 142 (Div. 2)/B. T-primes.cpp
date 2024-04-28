#include <bits/stdc++.h>

using i64 = long long;

const int inf = 1e6 + 100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    auto is_prime = [&](int x)
    {
        if (x <= 1)
            return false;
        if (x == 2)
            return true;

        for (int i = 2; i <= x / i; i++)
            if (x % i == 0)
                return false;
        return true;
    };

    while (n--)
    {
        i64 x;
        std::cin >> x;
        if ((i64)sqrt(x) * (i64)sqrt(x) == x && is_prime((i64)sqrt(x)))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}