#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int w, a, b;
    std::cin >> w >> a >> b;

    if (a <= b && a + w >= b || b <= a && b + w >= a)
        std::cout << 0 << '\n';
    else
    {
        int res = 0;
        res = std::min(abs(a - b - w), abs(b - a - w));
        std::cout << res << '\n';
    }

    return 0;
}