#include <bits/stdc++.h>

using i64 = long long;

const long double pi = acos(-1.0);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<long double, int>> angle(n);
    for (int i = 0; i < n; i++)
    {
        long double x, y;
        std::cin >> x >> y;
        angle[i].first = std::atan2(y, x);
        angle[i].second = i + 1;
    }

    std::sort(angle.begin(), angle.end());

    int ans1, ans2;
    long double min = 2 * pi;
    for (int i = 0; i < n; i++)
    {
        long double tmp = angle[(i + 1) % n].first - angle[i].first;
        if (tmp < 0)
            tmp += 2 * pi;
        if (tmp < min)
            min = tmp, ans1 = angle[i].second, ans2 = angle[(i + 1) % n].second;
    }
    std::cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}