#include <bits/stdc++.h>

using i64 = long long;

const int N = 510, INF = 0x3f3f3f3f;

int g[N][N], dis[N];
int n, m;
bool st[N];

int prim()
{
    memset(dis, 0x3f, sizeof dis);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (x == -1 || dis[x] > dis[j]))
                x = j;

        if (i && dis[x] == INF)
            return INF;

        if (i)
            res += dis[x];
        st[x] = true;

        for (int j = 1; j <= n; j++)
            dis[j] = std::min(dis[j], g[x][j]);
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(g, 0x3f, sizeof(g));

    std::cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        std::cin >> a >> b >> w;
        g[a][b] = g[b][a] = std::min(g[a][b], w);
    }

    int t = prim();
    if (t == INF)
        std::cout << "impossible\n";
    else
        std::cout << t << "\n";

    return 0;
}