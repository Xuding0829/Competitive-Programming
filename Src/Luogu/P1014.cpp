#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k = 1;
    std::cin >> n;

    while (n > k)
        n -= k, k++;
    if (k & 1)
        std::cout << k + 1 - n << '/' << n;
    else
        std::cout << n << '/' << k + 1 - n;

    return 0;
}