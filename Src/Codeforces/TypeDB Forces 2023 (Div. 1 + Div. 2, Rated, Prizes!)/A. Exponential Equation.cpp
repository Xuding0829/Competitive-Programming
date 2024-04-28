#include <bits/stdc++.h>

using i64 = long long;

i64 my_pow(int x, int y) // 求 x^y
{
    i64 res = 1;
    for (int i = 1; i <= y; i++)
    {
        res *= x;
        if (res > 1e9)
            return 1e9 + 1;
    }
    return res;
}

void solve()
{
    int n;
    std::cin >> n;

    if (!(n % 2))
        std::cout << n / 2 << ' ' << 1 << '\n';
    else
    {
        // for (int i = 2; i <= 30; i++)
        //     for (int j = 2; j <= 30; j++)
        //     {
        //         if (my_pow(i, j) * j + my_pow(j, i) * i == n)
        //         {
        //             std::cout << i << ' ' << j << '\n';
        //             return;
        //         }
        //     }
        std::cout << -1 << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}