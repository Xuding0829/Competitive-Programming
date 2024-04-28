#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::map<char, int> mp;
    for (auto i : s1)
        mp[i]++;

    if (mp['a'] == 0 || mp['b'] == 0 || mp['c'] == 0)
    {
        std::sort(s1.begin(), s1.end());
        std::cout << s1 << '\n';
        return;
    }

    if (s2[0] == 'b' || s2[0] == 'c')
    {
        std::sort(s1.begin(), s1.end());
        std::cout << s1 << '\n';
    }
    else // s2[0] = 'a'
    {
        std::sort(s1.begin(), s1.end());

        std::string t1, t2, t3, t4;
        for (auto i : s1)
        {
            if (i == 'a')
                t1 += i;
            else if (i == 'b')
                t2 += i;
            else if (i == 'c')
                t3 += i;
            else
                t4 += i;
        }

        std::sort(t4.begin(), t4.end());

        if (s2[1] == 'b')
            std::cout << t1 << t3 << t2 << t4 << '\n';
        else
            std::cout << t1 << t2 << t3 << t4 << '\n';
    }
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