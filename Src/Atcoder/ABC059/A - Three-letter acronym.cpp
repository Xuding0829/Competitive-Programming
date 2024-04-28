#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::cout << (char)(a[0] >= 'A' && a[0] <= 'Z' ? a[0] : a[0] - 32);
    std::cout << (char)(b[0] >= 'A' && b[0] <= 'Z' ? b[0] : b[0] - 32);
    std::cout << (char)(c[0] >= 'A' && c[0] <= 'Z' ? c[0] : c[0] - 32);

    return 0;
}