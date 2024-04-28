#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b >> c;

    if (c <= b && c >= a)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    return 0;
}