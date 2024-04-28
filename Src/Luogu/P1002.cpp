#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    x1 += 2, y1 += 2, x2 += 2, y2 += 2;

    std::vector<std::vector<i64>> f(40, std::vector<i64>(40));

    std::vector<std::vector<bool>> st(40, std::vector<bool>(40));
    std::vector<int> nx = {1, 1, -1, -1, 2, 2, -2, -2, 0};
    std::vector<int> ny = {2, -2, 2, -2, 1, -1, 1, -1, 0};
    for (int i = 0; i < 9; i++)
    {
        int x = x2 + nx[i], y = y2 + ny[i];
        st[x][y] = true;
    }

    f[2][2] = 1;
    for (int i = 2; i <= x1; i++)
    {
        for (int j = 2; j <= y1; j++)
        {
            if (st[i][j])
                continue;
            if (i == 2 && j == 2)
                continue;
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    std::cout << f[x1][y1] << '\n';

    return 0;
}