#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    getline(std::cin, s);

    int res = 0;
    for (auto i : s)
        if (i != ' ')
            res++;
    std::cout << res;

    return 0;
}