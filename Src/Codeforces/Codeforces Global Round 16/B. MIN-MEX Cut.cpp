#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0' && (s[i - 1] != '0' || i == 0))
            res++;

    std::cout << std::min(res, 2) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}