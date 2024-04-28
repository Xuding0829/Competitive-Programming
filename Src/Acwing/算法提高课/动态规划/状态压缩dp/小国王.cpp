#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 11, M = 1 << 11;
i64 f[N][N * N][M];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> state, cnt(M);
    auto check = [&](int state)
    {
        for (int i = 0; i < n; i++)
        {
            if ((state >> i & 1) && (state >> i + 1 & 1))
                return false;
        }
        return true;
    };

    auto count = [&](int state)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += state >> i & 1;
        return cnt;
    };

    for (int i = 0; i < 1 << n; i++)
    {
        if (check(i))
            state.push_back(i), cnt[i] = count(i);
    }

    std::vector<int> head[M];
    for (auto fir : state)
        for (auto sec : state)
            if (check(fir | sec) && !(fir & sec))
                head[fir].push_back(sec);

    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (auto fir : state)
                for (auto sec : head[fir])
                    if (j - cnt[fir] >= 0)
                        f[i][j][fir] += f[i - 1][j - cnt[fir]][sec];

    i64 res = 0;
    for (auto s : state)
        res += f[n][k][s];
    std::cout << res << '\n';
    return 0;
}