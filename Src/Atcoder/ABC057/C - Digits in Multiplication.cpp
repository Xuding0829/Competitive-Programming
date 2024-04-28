#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    auto get_num = [](i64 x)
    {
        int cnt = 0;
        while (x)
        {
            x /= 10;
            cnt++;
        }
        return cnt;
    };

    int res = 100;
    for (i64 i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            i64 x = get_num(i), y = get_num(n / i);
            int tmp = std::max(x, y);
            res = std::min(res, tmp);
        }
    }
    std::cout << res << '\n';
    return 0;
}