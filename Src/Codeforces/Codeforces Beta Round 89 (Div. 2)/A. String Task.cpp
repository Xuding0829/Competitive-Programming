#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    for (auto &i : s)
        if (i >= 'A' && i <= 'Z')
            i = i - 'A' + 'a';

    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'y' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            s.erase(i, 1), i = i - 1;
    for (auto i : s)
        std::cout << '.' << i;
    return 0;
}