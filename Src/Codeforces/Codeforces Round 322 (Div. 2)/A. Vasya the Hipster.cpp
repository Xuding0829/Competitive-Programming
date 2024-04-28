#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;

    std::cout << std::min(a, b) << ' ' << (a + b) / 2 - std::min(a, b);

    return 0;
}