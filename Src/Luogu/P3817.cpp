#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;

    i64 res = 0;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i - 1] + a[i] > x)
        {
            res += a[i - 1] + a[i] - x;
            a[i] -= a[i - 1] + a[i] - x;
        }
    }
    std::cout << res << '\n';

    return 0;
}