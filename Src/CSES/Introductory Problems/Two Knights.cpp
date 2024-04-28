#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        i64 res = 0, cnt1 = i * i, cnt2 = cnt1 - 1, tol = 2 * (i - 1) * (i - 2);
        i64 tmp = cnt1 * cnt2 / 2;
        res = tmp - 2 * tol;
        std::cout << res << '\n';
    }

    return 0;
}