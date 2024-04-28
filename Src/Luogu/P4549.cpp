#include <bits/stdc++.h>

using i64 = long long;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int res;
    std::cin >> res;
    for (int i = 1, x; i < n; i++)
    {
        std::cin >> x;
        res = gcd(abs(x), abs(res));
    }
    std::cout << res << '\n';
    return 0;
}