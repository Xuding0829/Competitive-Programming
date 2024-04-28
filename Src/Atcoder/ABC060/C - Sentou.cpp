#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    std::cin >> n >> t;

    std::vector<int> time(n);
    for (int i = 0; i < n; i++)
        std::cin >> time[i];

    i64 res = t, now = t;
    for (int i = 1; i < n; i++)
    {
        if (now > time[i])
            res += t - now + time[i];
        else
            res += t;
        now = time[i] + t;
    }
    std::cout << res << '\n';

    return 0;
}