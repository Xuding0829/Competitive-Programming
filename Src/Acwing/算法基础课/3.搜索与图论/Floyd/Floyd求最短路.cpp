#include <bits/stdc++.h>

using i64 = long long;

const int N = 210, INF = 1e9;

int d[N][N];
int n, m, q;

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;

    while (m--)
    {
        int a, b, w;
        std::cin >> a >> b >> w;
        d[a][b] = std::min(d[a][b], w);
    }

    floyd();

    while (q--)
    {
        int a, b;
        std::cin >> a >> b;
        int t = d[a][b];
        if (t > INF / 2)
            std::cout << "impossible\n";
        else
            std::cout << t << "\n";
    }

    return 0;
}