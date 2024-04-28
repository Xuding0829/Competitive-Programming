#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int op[8][7] = {
        {0, 2, 6, 11, 15, 20, 22},
        {1, 3, 8, 12, 17, 21, 23},
        {10, 9, 8, 7, 6, 5, 4},
        {19, 18, 17, 16, 15, 14, 13},
        {23, 21, 17, 12, 8, 3, 1},
        {22, 20, 15, 11, 6, 2, 0},
        {13, 14, 15, 16, 17, 18, 19},
        {4, 5, 6, 7, 8, 9, 10}};
    int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};
    int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};

    std::vector<int> q(25);
    while (std::cin >> q[0], q[0])
    {
        for (int i = 1; i < 24; i++)
            std::cin >> q[i];

        int dep = 0;
        std::vector<int> path(100);

        auto f = [&]()
        {
            static int cnt[4];
            memset(cnt, 0, sizeof cnt);
            for (int i = 0; i < 8; i++)
                cnt[q[center[i]]]++;

            int s = 0;
            for (int i = 0; i < 4; i++)
                s = std::max(s, cnt[i]);
            return 8 - s;
        };

        auto check = [&]()
        {
            for (int i = 1; i < 8; i++)
                if (q[center[i]] != q[center[0]])
                    return false;
            return true;
        };

        auto opearation = [&](int x)
        {
            int t = q[op[x][0]];
            for (int i = 0; i < 6; i++)
                q[op[x][i]] = q[op[x][i + 1]];
            q[op[x][6]] = t;
        };

        std::function<bool(int, int, int)> dfs = [&](int u, int dep, int last)
        {
            if (u + f() > dep)
                return false;
            if (check())
                return true;
            for (int i = 0; i < 8; i++)
            {
                if (opposite[i] == last)
                    continue;
                opearation(i);
                path[u] = i;
                if (dfs(u + 1, dep, i))
                    return true;
                opearation(opposite[i]);
            }
            return false;
        };

        while (!dfs(0, dep, -1))
            dep++;

        if (!dep)
            std::cout << "No moves needed";
        for (int i = 0; i < dep; i++)
            std::cout << char('A' + path[i]);
        std::cout << '\n'
                  << q[6] << '\n';
    }

    return 0;
}