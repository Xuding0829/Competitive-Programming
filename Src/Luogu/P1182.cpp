#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
        std::cin >> a[i], l = std::max(l, a[i]), r += a[i];

    auto check = [=](int k)
    {
        int tmp = 0, cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] + tmp > k)
                tmp = 0, cnt++;
            tmp += a[i];
        }
        return cnt <= m;
    };

    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << '\n';

    return 0;
}