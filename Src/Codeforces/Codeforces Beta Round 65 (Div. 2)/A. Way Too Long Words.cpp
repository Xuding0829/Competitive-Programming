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

        if (s.size() <= 10)
            std::cout << s << '\n';
        else
            std::cout << s[0] << s.size() - 2 << s[s.size() - 1] << "\n";
    }

    return 0;
}