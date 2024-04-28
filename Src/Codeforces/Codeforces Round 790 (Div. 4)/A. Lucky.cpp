#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int res = 0, res2 = 0;
    for (int i = 0; i < 3; i++)
        res += s[i] - '0';
    for (int i = 3; i < 6; i++)
        res2 += s[i] - '0';

    std::cout << (res == res2 ? "YES\n" : "NO\n");
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