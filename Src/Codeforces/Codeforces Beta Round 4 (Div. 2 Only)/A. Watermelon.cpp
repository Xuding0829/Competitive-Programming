#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n % 2 == 0 && n >= 4)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    return 0;
}