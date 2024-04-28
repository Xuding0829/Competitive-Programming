#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '4' || s[i] == '7')
            res++;
    std::cout << (res == 4 || res == 7 ? "YES" : "NO");
    return 0;
}