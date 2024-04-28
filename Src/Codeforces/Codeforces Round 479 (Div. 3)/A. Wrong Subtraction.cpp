#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    while (m > 0)
    {
        if (n % 10 == 0)
            n /= 10, m--;
        else
            n--, m--;
    }
    std::cout << n << '\n';
    return 0;
}