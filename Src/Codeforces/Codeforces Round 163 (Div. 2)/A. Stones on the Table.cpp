#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::string s;
    std::cin >> n >> s;

    int res = 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1])
            res++, s.erase(i, 1), i = i - 1;
    std::cout << res << '\n';
    return 0;
}