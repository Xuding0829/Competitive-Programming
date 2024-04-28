#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<std::string, int> mp;
    while (n--)
    {
        std::string s;
        std::cin >> s;

        if (!mp[s])
        {
            std::cout << "OK\n";
            mp[s] = 1;
        }
        else
        {
            mp[s]++;
            std::cout << s << mp[s] - 1 << '\n';
        }
    }

    return 0;
}