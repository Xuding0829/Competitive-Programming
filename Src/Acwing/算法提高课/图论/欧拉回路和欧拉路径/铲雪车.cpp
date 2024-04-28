#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    double res = 0;
    int x1, y1, x2, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2)
    {
        double dx = x1 - x2, dy = y1 - y2;
        res += std::sqrt(dx * dx + dy * dy) * 2;
    }

    int minutes = std::round(res / 1000 / 20 * 60);
    int hour = minutes / 60;
    minutes %= 60;
    printf("%d:%02d\n", hour, minutes);
    return 0;
}