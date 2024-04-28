#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<std::string, int> mp;

    int n;
    std::string s;
    std::cin >> n >> s;

    for (int i = 0; i < n - 1; i++)
        mp[s.substr(i, 2)]++;

    std::string t;
    int mx = 0;
    for (auto [u, v] : mp)
    {
        if (v > mx)
        {
            mx = v;
            t = u;
        }
    }
    std::cout << t << '\n';

    return 0;
}