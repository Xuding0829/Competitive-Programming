#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;

    if (a.size() == b.size())
    {
        if (a == b)
            std::cout << "EQUAL";
        else if (a > b)
            std::cout << "GREATER\n";
        else
            std::cout << "LESS\n";
    }
    else
        std::cout << (a.size() > b.size() ? "GREATER\n" : "LESS\n");

    return 0;
}