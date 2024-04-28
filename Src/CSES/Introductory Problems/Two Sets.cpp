#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n % 4 == 1 || n % 4 == 2)
        std::cout << "NO\n";
    else if (n % 4 == 0)
    {
        std::cout << "YES\n";
        std::cout << n / 2 << '\n';
        for (int i = 1; i <= n / 2; i += 2)
            std::cout << i << ' ' << n - i + 1 << ' ';
        std::cout << '\n'
                  << n / 2 << '\n';
        for (int i = 2; i <= n / 2; i += 2)
            std::cout << i << ' ' << n - i + 1 << " \n"[i == n / 2];
    }
    else
    {
        std::cout << "YES\n";
        std::cout << n / 2 << '\n';
        for (int i = 2; i <= n / 2; i += 2)
            std::cout << i << ' ' << n - i << ' ';
        std::cout << n << '\n';

        std::cout << n / 2 + 1 << '\n';
        for (int i = 1; i <= n / 2; i += 2)
            std::cout << i << ' ' << n - i << ' ';
        std::cout << '\n';
    }

    return 0;
}