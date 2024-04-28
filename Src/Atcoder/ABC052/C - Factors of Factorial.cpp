#include <bits/stdc++.h>

using i64 = long long;
const int mod = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        for (int j = 2; j <= x / j; j++)
        {
            if (x % j == 0)
            {
                int s = 0;
                while (x % j == 0)
                    x /= j, s++;
                a[j] += s;
            }
        }
        if (x > 1)
            a[x]++;
    }

    // for (int i = 1; i < a.size(); i++)
    //     std::cout << i << ' ' << a[i] << '\n';

    i64 res = 1;
    for (int i = 1; i < a.size(); i++)
        if (a[i])
            res = (res % mod * (a[i] + 1) % mod) % mod;
    std::cout << res << '\n';

    return 0;
}