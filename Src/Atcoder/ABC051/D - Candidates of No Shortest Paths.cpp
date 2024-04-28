#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = 0x3f3f3f;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = c;
    }

    std::vector<std::vector<int>> dis_backup(dis);

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (dis[i][j] != 0x3f3f3f && dis_backup[i][j] != 0x3f3f3f && dis[i][j] != dis_backup[i][j])
            {
                res++;
                //std::cout << "dis " << i << ' ' << j << ' '<< dis[i][j] << ' ' << "dis_backup " << i << ' ' << j << ' ' << dis_backup[i][j] << '\n';
            }

    std::cout << res << '\n';

    return 0;
}