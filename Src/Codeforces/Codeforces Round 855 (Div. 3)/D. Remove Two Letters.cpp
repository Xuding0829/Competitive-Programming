#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int res = 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i - 1] != s[i + 1])
            res++;
    std::cout << res << '\n';
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