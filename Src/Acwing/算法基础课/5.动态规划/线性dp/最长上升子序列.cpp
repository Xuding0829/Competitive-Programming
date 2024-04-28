#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j <= i; j++)
            if (a[i] > a[j])
                f[i] = std::max(f[i], f[j] + 1);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = std::max(res, f[i]);
    std::cout << res << '\n';
    return 0;
}