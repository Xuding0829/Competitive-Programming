#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int res = 0;

    auto get_f = [&](int n)
    {
        int res = 0;
        std::string t = std::to_string(n);
        for (auto c : t)
            res += c - '0';
        return res;
    };

    auto get_g = [&](int n, int r)
    {
        int res = 0;
        while (n)
        {
            res += n % r;
            n /= r;
        }
        return res;
    };

    for (int i = 1; i <= n; i++)
        res += (get_f(i) == get_g(i, 2));

    std::cout << res << '\n';

    return 0;
}