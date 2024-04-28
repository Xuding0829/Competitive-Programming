#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    i64 res = n / 11 * 2;
    n = n % 11;
    if(n >= 1 && n <= 6)
        res++;
    else if(n >= 7 && n <= 11)
        res += 2;
    std::cout << res << '\n';

    return 0;
}
/*

    i64 res = 0, mod = 11;
    if (n <= 6)
    {
        std::cout << 1 << '\n';
    }
    else if (n >= 7 && n <= 11)
    {
        std::cout << 2 << '\n';
    }
    else
    {
        res = n / mod * 2;
        n = n % mod;
        if(n >=1 && n <= 6)
            res++;
        else if(n >= 7 && n <= 11)
            res += 2;
        std::cout << res << '\n';
    }

*/