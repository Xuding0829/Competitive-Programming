#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    int res = 0;
    std::vector<bool> vis(26);
    for (int i = 0; i < n; i++)
    {
        res++;
        res += !vis[s[i] - 'A'];
        vis[s[i] - 'A'] = true;
    }
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