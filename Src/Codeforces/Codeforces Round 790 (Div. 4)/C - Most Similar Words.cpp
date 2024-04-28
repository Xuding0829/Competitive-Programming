#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];
    std::sort(s.begin(), s.end());

    int res = 1e9;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int tmp = 0;
            for (int k = 0; k < m; k++)
                tmp += abs(s[i][k] - s[j][k]);
            res = std::min(res, tmp);
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