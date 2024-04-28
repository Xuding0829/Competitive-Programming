#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> f(n);
    for (int i = 0; i < n; i++)
    {
        f[i] = a[i];
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                f[i] = std::max(f[i], f[j] + a[i]);
    }

    i64 res = 0;
    for (int i = 0; i < n; i++)
        res = std::max(res, f[i]);
    std::cout << res << '\n';

    return 0;
}