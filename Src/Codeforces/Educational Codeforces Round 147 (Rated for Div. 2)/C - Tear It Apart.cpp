#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<int> p[26];
    for (int i = 0; i < n; i++)
        p[s[i] - 'a'].push_back(i);

    int ans = n;
    for (int x = 0; x < 26; x++)
    {
        int t = -1, res = 0;
        p[x].push_back(n);
        for (auto i : p[x])
        {
            int len = i - t - 1;
            t = i;
            if (len)
                res = std::max(res, (int)ceil(log2(len + 1)));
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << '\n';
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