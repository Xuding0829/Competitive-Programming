#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, c;
    std::cin >> n >> c;

    std::map<i64, i64> mp;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], mp[a[i]]++, a[i] -= c;
    std::sort(a.begin(), a.end());

    i64 res = 0;
    for (int i = 0; i < n; i++)
        res += mp[a[i]];

    std::cout << res << '\n';

    return 0;
}