#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?' && s[i - 1] == '0')
            s[i] = '0';
        else if (s[i] == '?' && s[i - 1] == '1')
            s[i] = '1';
        else if (!i && s[i] == '?')
            s[i] = '0';
    }
    std::cout << s << '\n';
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