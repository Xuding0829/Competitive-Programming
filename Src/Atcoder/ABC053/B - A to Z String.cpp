#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int res = 0, tmp = 0;
    bool st = false;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A' && !st)
            res = i, st = !st;
        if(s[i] == 'Z')
            tmp = i;
    }
    res = tmp - res + 1;
    std::cout << res << '\n';

    return 0;
}