#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1e-4;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double a, b, c, d;
    std::cin >> a >> b >> c >> d;

    auto f = [&](double x)
    {
        return a * x * x * x + b * x * x + c * x + d;
    };

    int cnt = 0;
    for (int i = -100; i <= 100; i++)
    {
        double l = i, r = i + 1;
        if (std::fabs(f(l)) < eps)
        {
            cnt++;
            std::cout << std::fixed << std::setprecision(2) << l << ' ';
        }
        else if (std::fabs(f(r)) < eps)
        {
            continue;
        }
        else if (f(l) * f(r) < 0)
        {
            while (r - l > eps)
            {
                double mid = (l + r) / 2;
                if (f(mid) * f(r) < 0)
                    l = mid;
                else
                    r = mid;
            }
            cnt++;
            std::cout << std::fixed << std::setprecision(2) << l << ' ';
        }
        if (cnt == 3)
            break;
    }

    return 0;
}