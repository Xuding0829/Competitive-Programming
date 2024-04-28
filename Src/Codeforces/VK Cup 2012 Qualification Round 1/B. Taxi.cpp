#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(5);
    for (int i = 0, x; i < n; i++)
        std::cin >> x, a[x]++;

    int res = a[4];
    if (a[3])
        res += a[3], a[1] = std::max(0, a[1] - a[3]);
    if (a[2] % 2 == 0)
        res += a[2] / 2;
    else
    {
        res += (a[2] + 1) / 2;
        a[1] = std::max(0, a[1] - 2);
    }
    if (a[1])
        res += a[1] / 4 + (a[1] % 4 ? 1 : 0);

    std::cout << res << '\n';

    return 0;
}