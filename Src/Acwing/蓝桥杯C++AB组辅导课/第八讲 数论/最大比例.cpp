#include <bits/stdc++.h>

using i64 = long long;

i64 gcd(i64 a, i64 b)
{
    return b ? gcd(b, a % b) : a;
}

i64 gcd_sub(i64 a, i64 b)
{
    if (a < b)
        std::swap(a, b);
    if (b == 1)
        return a;
    return gcd_sub(b, a / b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<i64> x(n), up, down;
    for (int i = 0; i < n; i++)
        std::cin >> x[i];
    std::sort(x.begin(), x.end());
    x.erase(std::unique(x.begin(), x.end()), x.end());

    for (int i = 0; i < x.size(); i++)
    {
        i64 d = gcd(x[i], x[0]);
        up.emplace_back(x[i] / d);
        down.emplace_back(x[0] / d);
    }

    i64 ans_up = up[0], ans_down = down[0];
    for (int i = 1; i < up.size(); i++)
    {
        ans_up = gcd_sub(up[i], ans_up);
        ans_down = gcd_sub(down[i], ans_down);
    }
    std::cout << ans_up << '/' << ans_down << '\n';
    return 0;
}