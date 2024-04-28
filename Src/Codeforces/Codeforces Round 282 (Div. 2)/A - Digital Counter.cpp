#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::map<int, int> mp;
    mp[0] = 2, mp[1] = 7, mp[2] = 2, mp[3] = 3, mp[4] = 3;
    mp[5] = 4, mp[6] = 2, mp[7] = 5, mp[8] = 1, mp[9] = 2;
    std::cout << mp[s[0] - '0'] * mp[s[1] - '0'] << '\n';

    return 0;
}