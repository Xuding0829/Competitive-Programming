#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n % 2 == 1)
        std::cout << "0\n";
    else
    {
        n /= 2;
        std::cout << ((n % 2 == 0 ? (n - 1) / 2 : n / 2)) << '\n';
    }

    return 0;
}