#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<int, bool> mp;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], mp[a[i]] = true;

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (mp[a[i] + a[j]])
                res++, mp[a[i] + a[j]] = false;
    std::cout << res << '\n';
    return 0;
}