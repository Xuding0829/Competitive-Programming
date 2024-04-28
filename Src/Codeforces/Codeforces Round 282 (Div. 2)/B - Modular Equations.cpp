#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;

    if (a == b)
    {
        std::cout << "infinity\n";
    }
    else if (a < b)
    {
        std::cout << "0\n";
    }
    else
    {
        int res = 0;
        int d = a - b;

        for (int i = 1; i <= d / i; i++)
        {
            if (d % i == 0)
            {
                if (i > b)
                    res++;
                if (d / i > b && d / i != i)
                    res++;
            }
        }
        std::cout << res << '\n';
    }

    return 0;
}