#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::string s, t;
    std::cin >> s >> t;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i] && i - k < 0 && i + k >= n)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    if (s == t)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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