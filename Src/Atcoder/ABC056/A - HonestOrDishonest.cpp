#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char a, b;
    std::cin >> a >> b;
    if (a == b)
        std::cout << "H\n";
    else
        std::cout << "D\n";

    return 0;
}