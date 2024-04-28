#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        std::string s;
        std::cin >> s;

        std::map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        for (char i = 'a'; i <= 'z'; i++)
            if (mp[i])
            {
                for (int j = 0; j < mp[i]; j++)
                    std::cout << i;
            }
        std::cout << '\n';
    }

    return 0;
}