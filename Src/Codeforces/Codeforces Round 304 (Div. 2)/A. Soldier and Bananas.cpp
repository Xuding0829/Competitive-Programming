#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, n, w;
    std::cin >> k >> n >> w;
    std::cout << std::max(0, (1 + w) * w / 2 * k - n) << '\n';

    return 0;
}