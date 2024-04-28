#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::string s1, s2;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s1 += s[i];
        else
            s1 += s[i] - 32;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s2 += s[i];
        else
            s2 += s[i] + 32;
    }

    int up = 0, low = 0;
    for (auto it : s)
        if (it >= 'A' && it <= 'Z')
            up++;
        else
            low++;

    if (up > low)
        std::cout << s1 << '\n';
    else
        std::cout << s2 << '\n';

    return 0;
}