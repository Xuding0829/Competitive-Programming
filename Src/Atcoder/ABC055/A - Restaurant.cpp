#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int res = n * 800 - 200 * (n / 15);
    std::cout << res << '\n';

    return 0;
}