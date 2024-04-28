#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        i64 a, b;
        std::cin >> a >> b;

        if (b == 1)
            std::cout << "NO\n";
        else
        {
            std::cout << "YES\n";
            std::cout << a << ' ' << (i64)a * b << ' ' << (i64)a * (b + 1) << '\n';
        }
    }

    return 0;
}