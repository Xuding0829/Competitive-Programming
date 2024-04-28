#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 1e8;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;

    auto count = [&](int state)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += state >> i & 1;
        return cnt;
    };

    auto check = [&](int state)
    {
        for (int i = 0; i < n; i++)
            if ((state >> i & 1) && (state >> i + 1 & 1))
                return false;
        return true;
    };

    std::vector<int> g(m + 1);
    for (int i = 1; i <= m; i++)
        for (int j = 1, x; j <= n; j++)
            std::cin >> x, g[i] = g[i] << 1 | !x;

    std::vector<int> cnt(1 << n), state;
    for (int i = 0; i < 1 << n; i++)
        if (check(i))
            state.push_back(i), cnt[i] = count(i);

    std::vector<int> head[1 << n];
    for (auto fir : state)
        for (auto sec : state)
            if (!(fir & sec))
                head[fir].push_back(sec);

    std::vector f(m + 2, std::vector<i64>(1 << n));
    f[0][0] = 1;
    for (int i = 1; i <= m + 1; i++)
        for (auto s : state)
            if (!(s & g[i]))
                for (auto x : head[s])
                    f[i][s] = (f[i][s] + f[i - 1][x]) % mod;

    i64 res = 0;
    for (auto s : state)
        (res += f[m][s]) %= mod;
    std::cout << res << '\n';

    return 0;
}