#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int res = 0, cnt = 1;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1])
            cnt++, res = std::max(res, cnt);
        else
            cnt = 1;

    std::cout << (res >= 7 ? "YES" : "NO");
    return 0;
}