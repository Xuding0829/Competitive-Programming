#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int res = 0;
    std::map<int, int> mp;
    for (auto i : s)
    {
        mp[i - 'a']++;
        res = std::max(mp[i - 'a'], res);
    }

    if (res == 4)
        std::cout << "-1\n";
    else if (res == 3)
        std::cout << "6\n";
    else if (res == 2)
        std::cout << "4\n";
    else
        std::cout << "4\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}