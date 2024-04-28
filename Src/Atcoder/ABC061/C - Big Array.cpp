#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, k;
    std::cin >> n >> k;

    std::vector<std::pair<i64, i64>> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i].first >> a[i].second;

    std::sort(a.begin(), a.end());

    std::vector<i64> s(n);
    s[0] = a[0].second;
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i].second;

    i64 res = 0;
    for (int i = 0; i < n; i++)
    {
        if (k <= s[i])
        {
            res = a[i].first;
            break;
        }
    }
    std::cout << res << '\n';

    return 0;
}