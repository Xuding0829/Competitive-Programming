#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m, n || m)
    {
        std::vector dis(n, std::vector<int>(n, inf));
        for (int i = 0; i < n; i++)
            dis[i][i] = 0;

        std::pair<int, int> res[n];

        bool flag = false; // flag 标记当前测试数据是否已经有解.如果有解,仍需读入数据

        for (int i = 1; i <= m; i++)
        {
            char a, t, b;
            std::cin >> a >> t >> b;
            // a < b

            int x = a - 'A';
            int y = b - 'A';

            if (!flag && dis[y][x] != inf)
                printf("Inconsistency found after %d relations.\n", i), flag = true; // 出现矛盾

            dis[x][y] = 1; // x -> y

            auto floyd = [&](int u) -> void
            {
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        dis[i][j] = std::min(dis[i][j], dis[i][u] + dis[u][j]);
            };

            floyd(x), floyd(y); // 以 x, y为中转点更新其余点

            auto judge = [&]()
            {
                for (int i = 0; i < n; i++)
                {
                    int cnt = 0;
                    for (int j = 0; j < n; j++)
                        if (dis[i][j] != inf)
                            cnt++;
                    res[i] = {cnt, i};
                    for (int j = 0; j < n; j++)
                        if (i != j && dis[j][i] != inf)
                            cnt++;
                    if (cnt != n)
                        return false;
                }
                std::sort(res, res + n, std::greater<>());
                return true;
            };

            if (!flag && judge())
            {
                printf("Sorted sequence determined after %d relations: ", i);
                for (int i = 0; i < n; i++)
                    std::cout << char(res[i].second + 'A');
                std::cout << ".\n";
                flag = true;
            } // 有解
        }

        if (!flag)
            std::cout << "Sorted sequence cannot be determined.\n"; // 无解
    }

    return 0;
}