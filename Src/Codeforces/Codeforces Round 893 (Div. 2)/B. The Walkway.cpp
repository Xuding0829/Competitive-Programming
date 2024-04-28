#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> s(m + 2);
    for (int i = 1; i <= m; i++)
        std::cin >> s[i];
    s[0] = 1 - d, s[m + 1] = n + 1;

    int sum = 0;
    for (int i = 1; i <= m + 1; i++)
        sum += (s[i] - s[i - 1] - 1) / d;

    int res = 1e9, cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int tmp = sum;
        tmp -= (s[i] - s[i - 1] - 1) / d;
        tmp -= (s[i + 1] - s[i] - 1) / d;
        tmp += (s[i + 1] - s[i - 1] - 1) / d;
        tmp += m - 1;
        if (tmp < res)
            res = tmp, cnt = 1;
        else if (tmp == res)
            cnt++;
    }
    std::cout << res << ' ' << cnt << '\n';
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
