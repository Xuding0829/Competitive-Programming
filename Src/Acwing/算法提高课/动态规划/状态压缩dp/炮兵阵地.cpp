#include <bits/stdc++.h>

using i64 = long long;
constexpr int M = 1 << 10;
int f[2][M][M];
std::vector<int> head[M];
std::vector<int> state, cnt(M);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    auto count = [&](int state)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
            cnt += state >> i & 1;
        return cnt;
    };

    auto check = [&](int state)
    {
        for (int i = 0; i < m; i++)
            if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
                return false;
        return true;
    };

    std::vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
        {
            char ch;
            std::cin >> ch;
            g[i] += (ch == 'H') << j;
        }

    // for (int i = 0; i < n; i++)
    //     std::cout << g[i] << '\n';

    for (int i = 0; i < 1 << m; i++)
        if (check(i))
            state.push_back(i), cnt[i] = count(i);

    for (auto a : state)
        for (auto b : state)
            if (!(a & b))
                head[a].push_back(b);

    for (int i = 1; i <= n; ++i)
        for (int st : state)
            if (!(g[i] & st))
                for (int p1 : head[st])
                    if (!(g[i - 1] & p1))
                        for (int p2 : head[p1])
                            if (!(st & p2))
                                f[i & 1][st][p1] = std::max(f[i & 1][st][p1], f[i - 1 & 1][p1][p2] + cnt[st]);

    int res = 0;
    for (auto s : state)
        for (auto x : head[s])
            res = std::max(res, f[n & 1][s][x]);
    std::cout << res << '\n';

    return 0;
}