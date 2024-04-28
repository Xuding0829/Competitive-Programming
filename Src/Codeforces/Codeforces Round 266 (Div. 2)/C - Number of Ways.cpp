#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<i64> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], s[i] = s[i - 1] + a[i];

    if (s[n] % 3 != 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    i64 res = 0, cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (s[i - 1] == s[n] / 3)
            cnt++;
        if (s[i] == s[n] / 3 * 2)
            res += cnt;
    }
    std::cout << res << '\n';
    return 0;
}