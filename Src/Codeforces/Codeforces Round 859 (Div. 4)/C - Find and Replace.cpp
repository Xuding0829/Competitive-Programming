#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j] && (j - i) & 1)
            {
                std::cout << "NO\n";
                return;
            }
        }
    std::cout << "YES\n";
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