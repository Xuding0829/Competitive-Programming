#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<std::string, std::string> mp;
    for (int i = 0; i < n; i++)
    {
        std::string a, b;
        std::cin >> a >> b;
        if (!mp.count(a))
            mp[b] = a;
        else
            mp[b] = mp[a], mp.erase(a);
    }
    std::cout << mp.size() << '\n';

    for (auto [b, a] : mp)
        std::cout << a << ' ' << b << '\n';
    return 0;
}