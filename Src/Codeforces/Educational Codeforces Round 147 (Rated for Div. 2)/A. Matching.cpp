#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int res = 1;
    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?' && !i)
            res *= 9, flag = true;
        else if (s[i] == '?' && i)
            res *= 10, flag = true;
        else if (s[i] > '0' && s[i] <= '9')
            res *= 1, flag = true;
        else if (s[i] == '0' && !i)
            break;
    }
    std::cout << (flag ? res : 0) << '\n';
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