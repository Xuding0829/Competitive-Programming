#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    int res = 0;
    while (t--)
    {
        std::string s;
        std::cin >> s;
        if (s == "++X")
            ++res;
        else if (s == "X++")
            res++;
        else if (s == "--X")
            --res;
        else
            res--;
    }
    std::cout << res << '\n';

    return 0;
}