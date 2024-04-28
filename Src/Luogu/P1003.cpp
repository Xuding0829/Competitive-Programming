#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n), g(n), k(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i] >> b[i] >> g[i] >> k[i];

    int x, y, res = -1;
    std::cin >> x >> y;
    for (int i = 0; i < n; i++)
    {
        if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i])
            res = i + 1;
    }
    std::cout << res << '\n';

    return 0;
}