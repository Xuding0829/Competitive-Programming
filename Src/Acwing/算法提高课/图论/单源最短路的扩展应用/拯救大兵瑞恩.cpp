#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr int N = 105;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, p, k;
    std::cin >> n >> m >> p >> k;

    auto get = [&](int x, int y)
    {
        return (x - 1) * m + y;
    };

    std::vector g(N, std::vector<int>(N, -1));
    while (k--)
    {
        int x1, y1, x2, y2, gi;
        std::cin >> x1 >> y1 >> x2 >> y2 >> gi;
        int z1 = get(x1, y1), z2 = get(x2, y2);
        g[z1][z2] = g[z2][z1] = gi;
    }

    std::vector<int> key(N);

    int s;
    std::cin >> s;
    while (s--)
    {
        int x, y, q;
        std::cin >> x >> y >> q;
        key[get(x, y)] |= 1 << q;
    }

    auto bfs = [&]()
    {
        std::queue<std::pair<int, int>> q;
        std::vector dis(N, std::vector<int>(1 << 11, inf));
        std::vector vis(N, std::vector<bool>(1 << 11));
        int t = get(1, 1);
        q.push({t, key[t]});
        dis[t][key[t]] = 0;
        vis[t][key[t]] = true;

        while (q.size())
        {
            auto tmp = q.front();
            q.pop();

            int prepos = tmp.first, prekey = tmp.second;

            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++)
            {
                int x = (prepos - 1) / m + 1 + dx[i];
                int y = (prepos - 1) % m + 1 + dy[i];
                int nowpos = get(x, y);
                int nowkey = prekey | key[nowpos];

                if (x < 1 || x > n || y < 1 || y > m)
                    continue;
                if (!g[nowpos][prepos])
                    continue;
                if (g[nowpos][prepos] != -1 && !(prekey >> g[nowpos][prepos] & 1))
                    continue;

                if (!vis[nowpos][nowkey])
                {
                    q.push({nowpos, nowkey});
                    vis[nowpos][nowkey] = true;
                    dis[nowpos][nowkey] = dis[prepos][prekey] + 1;
                }

                if (nowpos == n * m)
                    return dis[nowpos][nowkey];
            }
        }
        return -1;
    };

    std::cout << bfs() << '\n';

    return 0;
}