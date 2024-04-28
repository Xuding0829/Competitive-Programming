#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1, s2;
    std::cin >> s1 >> s2;

    for (auto &i : s1)
        if (i >= 'A' && i <= 'Z')
            i = i - 'A' + 'a';

    for (auto &i : s2)
        if (i >= 'A' && i <= 'Z')
            i = i - 'A' + 'a';

    // std::cout << s1 << ' ' << s2 << '\n';

    if (s1 == s2)
        std::cout << "0\n";
    else
        std::cout << (s1 > s2 ? "1\n" : "-1\n");
    return 0;
}