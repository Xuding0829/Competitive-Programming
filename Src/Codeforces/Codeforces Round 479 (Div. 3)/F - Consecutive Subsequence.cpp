#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int len = 0, mx = 0;
    std::map<int, int> mp;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        mp[a[i]] = mp[a[i] - 1] + 1;
        if (mp[a[i]] > len)
            mx = a[i], len = mp[a[i]];
    }

    std::cout << len << '\n';
    mx = mx - len + 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == mx)
            std::cout << i << ' ', mx++;
    }
    return 0;
}