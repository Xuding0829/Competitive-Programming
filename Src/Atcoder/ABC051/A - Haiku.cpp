#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    for (int i = 0; s[i]; i++)
        if(s[i] == ',')
            s[i] = ' ';

    std::cout << s << "\n";

    return 0;
}