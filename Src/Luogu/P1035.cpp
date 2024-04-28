#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, n = 1;
    std::cin >> k;

    double s = 0;
    while (s <= k)
        s += 1.0 / n++;
    std::cout << --n << '\n';

    return 0;
}