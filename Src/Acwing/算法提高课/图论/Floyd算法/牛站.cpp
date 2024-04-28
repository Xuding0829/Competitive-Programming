#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1010;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t, s, e;
    std::cin >> n >> t >> s >> e;

    int cnt = 0;
    std::map<int, int> mp;
    if (!mp[s])
        mp[s] = cnt++;
    if (!mp[e])
        mp[e] = cnt++;
    s = mp[s], e = mp[e];
    std::vector g(N, std::vector<int>(N, inf));
    while (t--)
    {
        int u, v, w;
        std::cin >> w >> u >> v;
        if (!mp.count(u))
            mp[u] = cnt++;
        if (!mp.count(v))
            mp[v] = cnt++;
        u = mp[u], v = mp[v];
        g[u][v] = g[v][u] = std::min(g[u][v], w);
    }

    std::vector res(cnt, std::vector<int>(cnt, inf));
    for (int i = 0; i < cnt; i++)
        res[i][i] = 0;

    auto mul = [&](std::vector<std::vector<int>> a, std::vector<std::vector<int>> b)
    {
        std::vector tmp(cnt, std::vector<int>(cnt, inf));
        for (int k = 0; k < cnt; k++)
            for (int i = 0; i < cnt; i++)
                for (int j = 0; j < cnt; j++)
                    tmp[i][j] = std::min(tmp[i][j], a[i][k] + b[k][j]);
        return tmp;
    };

    while (n)
    {
        if (n & 1)
            res = mul(res, g); // res = res * g
        g = mul(g, g);         // g = g * g
        n >>= 1;
    }
    std::cout << res[s][e] << '\n';

    return 0;
}