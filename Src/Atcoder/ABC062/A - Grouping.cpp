#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<int, int> mp;
    mp[1] = mp[3] = mp[5] = mp[7] = mp[8] = mp[10] = mp[12] = 1;
    mp[4] = mp[6] = mp[9] = mp[11] = 2, mp[2] = 3;

    int x, y;
    std::cin >> x >> y;
    std::cout << (mp[x] == mp[y] ? "Yes" : "No");

    return 0;
}