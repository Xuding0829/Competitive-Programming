#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 a, b;
    std::cin >> a >> b;
    std::cout << (abs(a - b) <= 1 ? "Brown\n" : "Alice\n");

    return 0;
}