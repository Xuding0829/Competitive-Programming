#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::map<std::string, bool> mp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        mp[a[i]] = true;
    }

    for (int i = 0; i < n; i++)
    {
        bool find = false;
        for (int j = 1; j < a[i].size(); j++)
        {
            std::string s1 = a[i].substr(0, j), s2 = a[i].substr(j);
            if (mp[s1] && mp[s2])
            {
                find = true;
                break;
            }
        }
        std::cout << find;
    }
    std::cout << '\n';
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