#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 base = 233;
constexpr i64 mod = 1e9 + 7;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    std::cin >> s >> t;

    s = " " + s, t = " " + t;

    int n = s.size() - 1, m = t.size() - 1;
    std::vector<i64> pow(n + 1), f(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * base + s[i] - 'a' + 1;
        pow[i] = pow[i - 1] * base;
    }

    i64 Hash = 0;
    for (int i = 1; i <= m; i++)
        Hash = Hash * base + t[i] - 'a' + 1;

    auto get = [&](int l, int r)
    {
        return (f[r] - f[l - 1] * pow[r - l + 1]);
    };

    std::vector<i64> pos(n + 1);
    for (int i = m; i <= n; i++)
    {
        if (get(i - m + 1, i) == Hash)
            pos[i] = i - m + 1;
    }

    std::vector<i64> dp(n + 1), sum1(n + 1), sum2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!pos[i])
            dp[i] = dp[i - 1];
        else
            dp[i] = (sum2[i - m] + i - m + 1) % mod;
        sum1[i] = (sum1[i - 1] + dp[i]) % mod;
        sum2[i] = (sum2[i - 1] + sum1[i]) % mod;
    }
    std::cout << sum1[n] << '\n';
    return 0;
}