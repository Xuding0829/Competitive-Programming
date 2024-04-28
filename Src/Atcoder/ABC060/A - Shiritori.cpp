#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b, c;
    std::cin >> a >> b >> c;
    if (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0])
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    return 0;
}