#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int res = 1, tmp = 1;
    for (int i = 1; i < n; i++)
    {
        if(s[i] == s[i - 1])
            tmp++, res = std::max(res, tmp);
        else
            tmp = 1;
    }
    std::cout << res + 1 << '\n';
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