#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1e-5;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double n, m, k;
    std::cin >> n >> m >> k;

    auto check = [&](double mid)
    {
        double sum = 0;
        for (int i = 1; i <= k; i++)
            sum += m / std::pow(1 + mid, i);
        return sum <= n;
    };

    double l = 0, r = 1000;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    std::cout << std::fixed << std::setprecision(1) << l * 100 << '\n';
    return 0;
}