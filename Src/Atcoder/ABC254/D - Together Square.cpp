#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 1, x = i;
        for (int j = 2; j <= n / j; j++)
        {
            int cnt = 0;
            if (x % j == 0)
            {
                while (x % j == 0)
                {
                    x /= j;
                    cnt++;
                }
                if (cnt & 1)
                    tmp *= j;
            }
        }

        if (x > 1)
            tmp *= x;

        for (int j = 1; j * j * tmp <= n; j++)
            res++;
    }
    std::cout << res << '\n';

    return 0;
}