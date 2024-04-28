#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n == 1)
        std::cout << "1\n";
    else if (n < 4 && n != 1)
        std::cout << "NO SOLUTION\n";
    else
    {
        for (int i = 2; i <= n; i += 2)
            std::cout << i << ' ';
        for (int i = 1; i <= n; i += 2)
            std::cout << i << ' ';
    }

    return 0;
}