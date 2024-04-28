#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n, k;
    std::cin >> m >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto check = [&](int mid)
    {
        int pos = 0, tmp = k;
        for (int i = 0; i < n; i++)
        {
            if (tmp < 0)
                break;
            if (a[i] - pos <= mid)
                pos = a[i];
            else
                pos = pos + mid, tmp--, i--;
        }
        return tmp >= 0;
    };

    int l = 0, r = m;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << '\n';
    return 0;
}