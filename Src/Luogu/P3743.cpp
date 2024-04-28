#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1e-6;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double n, p;
    std::cin >> n >> p;

    double s = 0;
    std::vector<double> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i] >> b[i], s += a[i];

    auto check = [&](double mid)
    {
        double tmp = mid * p, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] * mid <= b[i])
                continue;
            else
                sum += (a[i] * mid - b[i]);
        }
        return sum <= tmp;
    };

    if (s <= p)
        std::cout << "-1\n";
    else
    {
        double l = 0, r = 1e10;
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        std::cout << std::fixed << std::setprecision(6) << l << '\n';
    }
    return 0;
}