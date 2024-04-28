#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    while (n != 1)
    {
        if (n % 2)
            std::cout << n << ' ', n = n * 3 + 1;
        else
            std::cout << n << ' ', n /= 2;
    }
    std::cout << n << '\n';
    return 0;
}