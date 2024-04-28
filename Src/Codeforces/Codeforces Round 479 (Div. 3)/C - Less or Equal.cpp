#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    auto check = [&](int x)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += (a[i] <= x);
        return cnt;
    };

    int l = 1, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }

    if (check(l) == k)
        std::cout << l << '\n';
    else
        std::cout << -1 << '\n';

    return 0;
}