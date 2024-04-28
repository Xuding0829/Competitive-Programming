#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d;
    std::cin >> a>> b >> c >>d;
    std::cout << std::max(a * b, c * d) << '\n';

    return 0;
}