#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    if (s[0] == '-')
    {
        s.erase(0, 1);
        std::reverse(s.begin(), s.end());
        while (s[0] == '0')
            s.erase(0, 1);
        std::cout << '-' << s << '\n';
    }
    else
    {
        std::reverse(s.begin(), s.end());
        while (s[0] == '0' && s.size() != 1)
            s.erase(0, 1);
        std::cout << s << '\n';
    }

    return 0;
}