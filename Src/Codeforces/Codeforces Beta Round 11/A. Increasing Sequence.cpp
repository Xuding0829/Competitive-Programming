
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] >= a[i + 1])
        {
            int tmp = (a[i] - a[i + 1]) / d;
            tmp++;
            res += tmp;
            a[i + 1] += tmp * d;
        }
    }

    // for (int i = 0; i < n; i++)
    //     std::cout << a[i] << ' ';
    // std::cout << '\n';

    std::cout << res << '\n';

    return 0;
}