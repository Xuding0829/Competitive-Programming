#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, s1;
    std::cin >> s;
    s1 = s, s1.pop_back(), std::reverse(s1.begin(), s1.end());
    std::cout << s << s1 << '\n';

    return 0;
}